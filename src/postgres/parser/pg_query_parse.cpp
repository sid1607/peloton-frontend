#include "parser/pg_query.h"
#include "pg_query_internal.h"
#include "pg_query_json.h"

#include "parser/parser.h"
#include "parser/analyze.h"
#include "parser/scanner.h"
#include "parser/scansup.h"
#include "rewrite/rewriteHandler.h"

#include <unistd.h>
#include <fcntl.h>

MemoryContext pg_query_enter_memory_context(const char* ctx_name)
{
	MemoryContext ctx = NULL;

	ctx = AllocSetContextCreate(TopMemoryContext,
								ctx_name,
								ALLOCSET_DEFAULT_MINSIZE,
								ALLOCSET_DEFAULT_INITSIZE,
								ALLOCSET_DEFAULT_MAXSIZE);
	MemoryContextSwitchTo(ctx);

	return ctx;
}

void pg_query_exit_memory_context(MemoryContext ctx)
{
	// Return to previous PostgreSQL memory context
	MemoryContextSwitchTo(TopMemoryContext);

	MemoryContextDelete(ctx);
}

PgQueryInternalParsetreeAndError pg_query_raw_parse(const char* input)
{
	PgQueryInternalParsetreeAndError result = {0};
	MemoryContext parse_context = CurrentMemoryContext;

	char stderr_buffer[STDERR_BUFFER_LEN + 1] = {0};
#ifndef DEBUG
	int stderr_global;
	int stderr_pipe[2];
#endif

#ifndef DEBUG
	// Setup pipe for stderr redirection
	if (pipe(stderr_pipe) != 0) {
		PgQueryError* error = malloc(sizeof(PgQueryError));

		error->message = strdup("Failed to open pipe, too many open file descriptors")

		result.error = error;

		return result;
	}

	fcntl(stderr_pipe[0], F_SETFL, fcntl(stderr_pipe[0], F_GETFL) | O_NONBLOCK);

	// Redirect stderr to the pipe
	stderr_global = dup(STDERR_FILENO);
	dup2(stderr_pipe[1], STDERR_FILENO);
	close(stderr_pipe[1]);
#endif

	PG_TRY();
	{
		result.tree = raw_parser(input);

#ifndef DEBUG
		// Save stderr for result
		read(stderr_pipe[0], stderr_buffer, STDERR_BUFFER_LEN);
#endif

		result.stderr_buffer = strdup(stderr_buffer);
	}
	PG_CATCH();
	{
		ErrorData* error_data;
		PgQueryError* error;

		MemoryContextSwitchTo(parse_context);
		error_data = CopyErrorData();

		// Note: This is intentionally malloc so exiting the memory context doesn't free this
		error = malloc(sizeof(PgQueryError));
		error->message   = strdup(error_data->message);
		error->filename  = strdup(error_data->filename);
		error->lineno    = error_data->lineno;
		error->cursorpos = error_data->cursorpos;

		result.error = error;
		FlushErrorState();
	}
	PG_END_TRY();

#ifndef DEBUG
	// Restore stderr, close pipe
	dup2(stderr_global, STDERR_FILENO);
	close(stderr_pipe[0]);
	close(stderr_global);
#endif

	return result;
}

PgQueryParseResult pg_query_parse(const char* input)
{
	MemoryContext ctx = NULL;
	PgQueryInternalParsetreeAndError parsetree_and_error;
	PgQueryParseResult result = {0};

	ctx = pg_query_enter_memory_context("pg_query_parse");

	parsetree_and_error = pg_query_raw_parse(input);

	// These are all malloc-ed and will survive exiting the memory context, the caller is responsible to free them now
	result.stderr_buffer = parsetree_and_error.stderr_buffer;
	result.error = parsetree_and_error.error;

	if (parsetree_and_error.tree != NULL) {
		char *tree_json;

		tree_json = pg_query_nodes_to_json(parsetree_and_error.tree);

		result.parse_tree = strdup(tree_json);
		pfree(tree_json);
	} else {
		result.parse_tree = strdup("[]");
	}

	pg_query_exit_memory_context(ctx);

	return result;
}

void pg_query_free_parse_result(PgQueryParseResult result)
{
  if (result.error) {
    free(result.error->message);
    free(result.error->filename);
    free(result.error);
  }

  free(result.parse_tree);
  free(result.stderr_buffer);
}

/*
 * Perform rewriting of a query produced by parse analysis.
 *
 * Note: query must just have come from the parser, because we do not do
 * AcquireRewriteLocks() on it.
 */
static List *
pg_rewrite_query(Query *query)
{
  List     *querytree_list;

  if (query->commandType == CMD_UTILITY)
  {
    /* don't rewrite utilities, just dump 'em into result list */
    querytree_list = list_make1(query);
  }
  else
  {
    /* rewrite regular queries */
    querytree_list = QueryRewrite(query);
  }

  return querytree_list;
}

/*
 * Given a raw parsetree (gram.y output), and optionally information about
 * types of parameter symbols ($n), perform parse analysis and rule rewriting.
 *
 * A list of Query nodes is returned, since either the analyzer or the
 * rewriter might expand one query to several.
 *
 * NOTE: for reasons mentioned above, this must be separate from raw parsing.
 */
List *
pg_analyze_and_rewrite(Node *parsetree, const char *query_string,
                       Oid *paramTypes, int numParams)
{
  Query    *query;
  List     *querytree_list;

  /*
   * (1) Perform parse analysis.
   */
  query = parse_analyze(parsetree, query_string, paramTypes, numParams);

  /*
   * (2) Rewrite the queries, as necessary
   */
  querytree_list = pg_rewrite_query(query);

  return querytree_list;
}

/*
 * Do raw parsing (only).
 *
 * A list of parsetrees is returned, since there might be multiple
 * commands in the given string.
 *
 * NOTE: for interactive queries, it is important to keep this routine
 * separate from the analysis & rewrite stages.  Analysis and rewriting
 * cannot be done in an aborted transaction, since they require access to
 * database tables.  So, we rely on the raw parser to determine whether
 * we've seen a COMMIT or ABORT command; when we are in abort state, other
 * commands are not processed any further than the raw parse stage.
 */
List *
pg_parse_query(const char *query_string)
{
  List     *raw_parsetree_list;

  raw_parsetree_list = raw_parser(query_string);

  return raw_parsetree_list;
}

