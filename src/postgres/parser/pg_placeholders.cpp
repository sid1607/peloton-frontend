//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// pg_placeholders.cpp
//
// Identification: src/postgres/parser/pg_placeholders.cpp
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "c.h"
#include "postgres.h"
#include "fmgr.h"

#include "access/tupdesc.h"
#include "access/htup.h"
#include "access/skey.h"
#include "access/relscan.h"
#include "catalog/namespace.h"
#include "parser/parse_node.h"
#include "nodes/relation.h"


void TupleDescInitEntry(tupleDesc*, short, char const*, unsigned int, int, int){ }
void transformExpr(ParseState*, Node*, ParseExprKind){ }
void get_commutator(unsigned int){ }
void CacheInvalidateRelcache(RelationData*){ }
void heap_freetuple(HeapTupleData*){ }
void get_element_type(unsigned int){ }
void relation_close(RelationData*, int){ }
void locate_var_of_level(Node*, int){ }
Datum OidFunctionCall1Coll(unsigned int, unsigned int, unsigned long){
  Datum tmp;
  return tmp;
}
void check_functional_grouping(unsigned int, unsigned int, unsigned int, List*, List**){ }
void numeric_in(FunctionCallInfoData*){ }
void ScanKeyInit(ScanKeyData*, short, unsigned short, unsigned int, unsigned long){ }

Relation try_relation_open(unsigned int, int){ return nullptr; }

Oid LookupNamespaceNoError(char const*){ return InvalidOid;}
void scanint8(char const*, bool, long*){ }
void IsCatalogRelation(RelationData*){ }
void simple_heap_update(RelationData*, ItemPointerData*, HeapTupleData*){ }
void hash_uint32(unsigned int){ }

int SQL_inheritance;

HeapTupleData *heap_getnext(HeapScanDescData*, ScanDirection){
  return nullptr;
}

void lookup_rowtype_tupdesc(unsigned int, int){ }
void get_typcollation(unsigned int){ }
Oid RangeVarGetRelidExtended(RangeVar const*, int, bool, bool, void (*)(RangeVar const*, unsigned int, unsigned int, void*), void*){
  return InvalidOid;
}
void get_rel_name(unsigned int){ }

Size add_size(unsigned long, unsigned long){
  Size s;
  return s;
}

void varstr_levenshtein(char const*, int, char const*, int, int, int, int){ }

Size mul_size(unsigned long, unsigned long){
  Size s;
  return s;
}

Relation relation_open(unsigned int, int){ return nullptr; }

void get_relid_attribute_name(unsigned int, short){ }
void getTypeIOParam(HeapTupleData*){ }
void SystemAttributeDefinition(short, bool){ }
int fetch_search_path_array(unsigned int*, int){ return 0; }
void DecrTupleDescRefCount(tupleDesc*){ }

HeapTupleData *systable_getnext(SysScanDescData*){
  return nullptr;
}

void varstr_levenshtein_less_equal(char const*, int, char const*, int, int, int, int, int){ }
void get_sortgroupclause_expr(SortGroupClause*, List*){ }
void lookup_type_cache(unsigned int, int){ }
void get_equality_op_for_ordering_op(unsigned int, bool*){ }
void defGetBoolean(DefElem*){ }
void op_hashjoinable(unsigned int, unsigned int){ }
void SearchSysCacheCopy(int, unsigned long, unsigned long, unsigned long, unsigned long){ }
void DeconstructQualifiedName(List*, char**, char**){ }
void heap_endscan(HeapScanDescData*){ }
void lookup_rowtype_tupdesc_copy(unsigned int, int){ }

TupleDesc CreateTemplateTupleDesc(int, bool){
  TupleDesc t;
  return t;
}

void CheckAttributeNamesTypes(tupleDesc*, char, bool){ }
void TupleDescCopyEntry(tupleDesc*, short, tupleDesc*, short){ }
void make_and_qual(Node*, Node*){ }
void type_is_range(unsigned int){ }

int SessionReplicationRole;

void get_func_variadictype(unsigned int){ }
void ParseExprKindName(ParseExprKind){ }

int s_lock(unsigned char volatile*, char const*, int){ return 0; }

void get_relation_constraint_oid(unsigned int, char const*, bool){ }

Datum OidInputFunctionCall(unsigned int, char*, unsigned int, int){
  Datum d;
  return d;
}

void get_func_result_name(unsigned int){ }
void TupleDescInitEntryCollation(tupleDesc*, short, unsigned int){ }
void ReleaseSysCache(HeapTupleData*){ }
void getBaseType(unsigned int){ }
void func_match_argtypes(int, unsigned int*, _FuncCandidateList*, _FuncCandidateList**){ }
void get_expr_result_type(Node*, unsigned int*, tupleDesc**){ }
void ParseTableSample(ParseState*, char*, Node*, List*, int){ }
FuncCandidateList OpernameGetCandidates(List*, char, bool){ FuncCandidateList fcl; return fcl;}
void get_atttype(unsigned int, short){ }
HeapScanDesc heap_beginscan_catalog(RelationData*, int, ScanKeyData*){ return nullptr;}
void bit_in(FunctionCallInfoData*){ }
void get_typdefault(unsigned int){ }

int default_with_oids;

void get_collation_name(unsigned int){ }
void get_row_security_policies(Query*, CmdType, RangeTblEntry*, int, List**, List**, bool*, bool*){ }
Relation heap_open(unsigned int, int){ return nullptr; }
void contain_vars_of_level(Node*, int){ }
void get_relname_relid(char const*, unsigned int){ }
void flatten_join_alias_vars(PlannerInfo*, Node*){ }
void get_sortgroupclause_tle(SortGroupClause*, List*){ }
void format_type_with_typemod(unsigned int, int){ }
void make_fn_arguments(ParseState*, List*, unsigned int*, unsigned int*){ }
Oid get_collation_oid(List*, bool){ return InvalidOid; }
void getBaseTypeAndTypmod(unsigned int, int*){ }
Oid OpernameGetOprid(List*, unsigned int, unsigned int){ return InvalidOid; }
void CacheInvalidateRelcacheByTuple(HeapTupleData*){ }
void get_type_category_preferred(unsigned int, char*, bool*){ }
void get_atttypetypmodcoll(unsigned int, short, unsigned int*, int*, unsigned int*){ }
void CacheRegisterSyscacheCallback(int, void (*)(unsigned long, int, unsigned int), unsigned long){ }
void GetSysCacheOid(int, unsigned long, unsigned long, unsigned long, unsigned long){ }
void get_sortgroupref_tle(unsigned int, List*){ }
void get_func_retset(unsigned int){ }
void SearchSysCache(int, unsigned long, unsigned long, unsigned long, unsigned long){ }
void GetCurrentTransactionNestLevel(){ }
void func_select_candidate(int, unsigned int*, _FuncCandidateList*){ }
Oid TypenameGetTypid(char const*){ return InvalidOid; }
void SystemAttributeByName(char const*, bool){ }
void get_opclass_oid(unsigned int, List*, bool){ }
void simple_heap_delete(RelationData*, ItemPointerData*){ }
Oid LookupExplicitNamespace(char const*, bool){ return InvalidOid; }
void CatalogUpdateIndexes(RelationData*, HeapTupleData*){ }
void get_database_name(unsigned int){ }
void *stringToNode(char*){ return nullptr; }
Relation heap_openrv_extended(RangeVar const*, int, bool){ return nullptr; }
SysScanDesc systable_beginscan(RelationData*, unsigned int, bool, SnapshotData*, int, ScanKeyData*){ return nullptr; }
void get_range_subtype(unsigned int){ }
void systable_endscan(SysScanDescData*){ }
void get_attnum(unsigned int, char const*){ }
void get_base_element_type(unsigned int){ }
void SearchSysCacheExists(int, unsigned long, unsigned long, unsigned long, unsigned long){ }
void type_is_enum(unsigned int){ }
void typeInheritsFrom(unsigned int, unsigned int){ }
void get_func_signature(unsigned int, unsigned int**, int*){ }
