//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// main.cpp
//
// Identification: src/main.cpp
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include <stdio.h>
#include <stdlib.h>

#include "parser/pg_query.h"

size_t testCount = 8;
const char* tests[] = {
    "SELECT 1",
    "SELECT * FROM x WHERE z = 2",
    "SELECT 5.41414",
    "SELECT $1",
    "SELECT ?",
    "SELECT 999999999999999999999::numeric/1000000000000000000000",
    "SELECT 4790999999999999999999999999999999999999999999999999999999999999999999999999999999999999 * 9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999",
    "SELECT film_id, title, rental_rate FROM film WHERE rental_rate > ( SELECT AVG (rental_rate) FROM film );"
};

int main() {
  List *parsetree_list, *querytree_list;
  ListCell *parsetree_item, *querytree_item;
  size_t i;

  pg_query_init();

  // TEST CASES
  for (i = 0; i < testCount; i++) {
    const char *query_string = tests[i];

    printf("\n\nQUERY STRING :: %s \n", query_string);

    parsetree_list = pg_parse_query(query_string);

    /*
     * Run through the raw parsetree(s) and process each one.
     */
    foreach(parsetree_item, parsetree_list)
    {
      Node     *parsetree = (Node *) lfirst(parsetree_item);

      char *parsetree_string = nodeToString(parsetree);

      printf("\nPARSETREE :: %s \n", parsetree_string);

      querytree_list = pg_analyze_and_rewrite(parsetree, query_string, NULL, 0);

      foreach(querytree_item, querytree_list)
      {
        Node     *querytree = (Node *) lfirst(querytree_item);

        char *querytree_string = nodeToString(querytree);

        printf("QUERYTREE :: %s \n", querytree_string);
      }


    }

  }

  return 0;
}
