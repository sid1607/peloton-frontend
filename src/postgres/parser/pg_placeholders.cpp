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
#include "catalog/pg_class.h"
#include "nodes/relation.h"
#include "parser/parse_node.h"
#include "utils/rel.h"

void TupleDescInitEntry(tupleDesc*, short, char const*, unsigned int, int, int){
  printf("TupleDescInitEntry\n");
}

void transformExpr(ParseState*, Node*, ParseExprKind){
  //printf("transformExpr\n");
}

void get_commutator(unsigned int){
  printf("get_commutator\n");
}

void CacheInvalidateRelcache(RelationData*){
  printf("CacheInvalidateRelcache\n");
}

void heap_freetuple(HeapTupleData*){
  printf("heap_freetuple\n");
}

void get_element_type(unsigned int){
  printf("get_element_type\n");
}

void relation_close(RelationData*, int){
  printf("relation_close\n");
}

void locate_var_of_level(Node*, int){
  printf("locate_var_of_level\n");
}

Datum OidFunctionCall1Coll(unsigned int, unsigned int, unsigned long){
  Datum tmp;
  printf("OidFunctionCall1Coll\n");
  return tmp;
}

void check_functional_grouping(unsigned int, unsigned int, unsigned int, List*, List**){
  printf("check_functional_grouping\n");
}

void numeric_in(FunctionCallInfoData*){
  printf("numeric_in\n");
}

void ScanKeyInit(ScanKeyData*, short, unsigned short, unsigned int, unsigned long){
  printf("ScanKeyInit\n");
}

Relation try_relation_open(unsigned int, int){
  printf("try_relation_open\n");
  return nullptr;
}

Oid LookupNamespaceNoError(char const*){
  printf("LookupNamespaceNoError\n");
  return InvalidOid;
}

void scanint8(char const*, bool, long*){
  printf("scanint8\n");
}

void IsCatalogRelation(RelationData*){
  printf("IsCatalogRelation\n");
}

void simple_heap_update(RelationData*, ItemPointerData*, HeapTupleData*){
  printf("simple_heap_update\n");
}

void hash_uint32(unsigned int){
  printf("hash_uint32\n");
}

int SQL_inheritance;

HeapTupleData *heap_getnext(HeapScanDescData*, ScanDirection){
  printf("heap_getnext\n");
  return nullptr;
}

void lookup_rowtype_tupdesc(unsigned int, int){
  printf("lookup_rowtype_tupdesc\n");
}

void get_typcollation(unsigned int){
  printf("get_typcollation\n");
}

Oid RangeVarGetRelidExtended(RangeVar const*, int, bool, bool, void (*)(RangeVar const*, unsigned int, unsigned int, void*), void*){
  printf("RangeVarGetRelidExtended\n");
  return InvalidOid;
}

void get_rel_name(unsigned int){
  printf("get_rel_name\n");
}

Size add_size(unsigned long, unsigned long){
  Size s;
  printf("add_size\n");
  return s;
}

void varstr_levenshtein(char const*, int, char const*, int, int, int, int){
  printf("varstr_levenshtein\n");
}

Size mul_size(unsigned long, unsigned long){
  Size s;
  printf("mul_size\n");
  return s;
}

Relation relation_open(unsigned int, int){
  printf("relation_open\n");
  return nullptr;
}

void get_relid_attribute_name(unsigned int, short){
  printf("get_relid_attribute_name\n");
}

void getTypeIOParam(HeapTupleData*){
  printf("getTypeIOParam\n");
}

void SystemAttributeDefinition(short, bool){
  printf("SystemAttributeDefinition\n");
}

int fetch_search_path_array(unsigned int*, int){
  printf("fetch_search_path_array\n");
  return 0;
}

void DecrTupleDescRefCount(tupleDesc*){
  printf("DecrTupleDescRefCount\n");
}

HeapTupleData *systable_getnext(SysScanDescData*){
  printf("systable_getnext\n");
  return nullptr;
}

void varstr_levenshtein_less_equal(char const*, int, char const*, int, int, int, int, int){
  printf("varstr_levenshtein_less_equal\n");
}

void get_sortgroupclause_expr(SortGroupClause*, List*){
  printf("get_sortgroupclause_expr\n");
}

void lookup_type_cache(unsigned int, int){
  printf("lookup_type_cache\n");
}

void get_equality_op_for_ordering_op(unsigned int, bool*){
  printf("get_equality_op_for_ordering_op\n");
}

void defGetBoolean(DefElem*){
  printf("defGetBoolean\n");
}

void op_hashjoinable(unsigned int, unsigned int){
  printf("op_hashjoinable\n");
}

void SearchSysCacheCopy(int, unsigned long, unsigned long, unsigned long, unsigned long){
  printf("SearchSysCacheCopy\n");
}

void DeconstructQualifiedName(List*, char**, char**){
  printf("DeconstructQualifiedName\n");
}

void heap_endscan(HeapScanDescData*){
  printf("heap_endscan\n");
}

void lookup_rowtype_tupdesc_copy(unsigned int, int){
  printf("lookup_rowtype_tupdesc_copy\n");
}

TupleDesc CreateTemplateTupleDesc(int, bool){
  TupleDesc t;
  printf("CreateTemplateTupleDesc\n");
  return t;
}

void CheckAttributeNamesTypes(tupleDesc*, char, bool){
  printf("CheckAttributeNamesTypes\n");
}

void TupleDescCopyEntry(tupleDesc*, short, tupleDesc*, short){
  printf("TupleDescCopyEntry\n");
}

void make_and_qual(Node*, Node*){
  printf("make_and_qual\n");
}

void type_is_range(unsigned int){
  printf("type_is_range\n");
}

int SessionReplicationRole;

void get_func_variadictype(unsigned int){
  printf("get_func_variadictype\n");
}

void ParseExprKindName(ParseExprKind){
  printf("ParseExprKindName\n");
}

int s_lock(unsigned char volatile*, char const*, int){
  printf("s_lock\n");
  return 0;
}

void get_relation_constraint_oid(unsigned int, char const*, bool){
  printf("get_relation_constraint_oid\n");
}

Datum OidInputFunctionCall(unsigned int, char*, unsigned int, int){
  Datum d;
  printf("OidInputFunctionCall\n");
  return d;
}

void get_func_result_name(unsigned int){
  printf("get_func_result_name\n");
}

void TupleDescInitEntryCollation(tupleDesc*, short, unsigned int){
  printf("TupleDescInitEntryCollation\n");
}

void ReleaseSysCache(HeapTupleData*){
  printf("ReleaseSysCache\n");
}

void getBaseType(unsigned int){
  printf("getBaseType\n");
}

void func_match_argtypes(int, unsigned int*, _FuncCandidateList*, _FuncCandidateList**){
  printf("func_match_argtypes\n");
}

void get_expr_result_type(Node*, unsigned int*, tupleDesc**){
  printf("get_expr_result_type\n");
}

void ParseTableSample(ParseState*, char*, Node*, List*, int){
  printf("ParseTableSample\n");
}

FuncCandidateList OpernameGetCandidates(List*, char, bool){
  FuncCandidateList fcl;
  printf("OpernameGetCandidates\n");
  return fcl;
}

void get_atttype(unsigned int, short){
  printf("get_atttype\n");
}

HeapScanDesc heap_beginscan_catalog(RelationData*, int, ScanKeyData*){
  printf("heap_beginscan_catalog\n");
  return nullptr;
}

void bit_in(FunctionCallInfoData*){
  printf("bit_in\n");}

void get_typdefault(unsigned int){
  printf("get_typdefault\n");
}

int default_with_oids;

void get_collation_name(unsigned int){
  printf("get_collation_name\n");
}

void get_row_security_policies(Query*, CmdType, RangeTblEntry*, int, List**, List**, bool*, bool*){
  printf("get_row_security_policies\n");
}

Relation heap_open(unsigned int, int){
  printf("heap_open\n");
  return nullptr;
}

void contain_vars_of_level(Node*, int){
  printf("contain_vars_of_level\n");
}

void get_relname_relid(char const*, unsigned int){
  printf("get_relname_relid\n");}

void flatten_join_alias_vars(PlannerInfo*, Node*){
  printf("flatten_join_alias_vars\n");}

void get_sortgroupclause_tle(SortGroupClause*, List*){
  printf("get_sortgroupclause_tle\n");
}

void format_type_with_typemod(unsigned int, int){
  printf("format_type_with_typemod\n");
}

void make_fn_arguments(ParseState*, List*, unsigned int*, unsigned int*){
  printf("make_fn_arguments\n");
}

Oid get_collation_oid(List*, bool){
  printf("get_collation_oid\n");
  return InvalidOid;
}

void getBaseTypeAndTypmod(unsigned int, int*){
  printf("getBaseTypeAndTypmod\n");
}

Oid OpernameGetOprid(List*, unsigned int, unsigned int){
  printf("OpernameGetOprid\n");
  return InvalidOid;
}

void CacheInvalidateRelcacheByTuple(HeapTupleData*){
  printf("CacheInvalidateRelcacheByTuple\n");
}

void get_type_category_preferred(unsigned int, char*, bool*){
  printf("get_type_category_preferred\n");
}

void get_atttypetypmodcoll(unsigned int, short, unsigned int*, int*, unsigned int*){
  printf("get_atttypetypmodcoll\n");
}

void CacheRegisterSyscacheCallback(int, void (*)(unsigned long, int, unsigned int), unsigned long){
  printf("CacheRegisterSyscacheCallback\n");
}

void GetSysCacheOid(int, unsigned long, unsigned long, unsigned long, unsigned long){
  printf("GetSysCacheOid\n");
}

void get_sortgroupref_tle(unsigned int, List*){
  printf("get_sortgroupref_tle\n");
}

void get_func_retset(unsigned int){
  printf("get_func_retset\n");
}

void SearchSysCache(int, unsigned long, unsigned long, unsigned long, unsigned long){
  printf("SearchSysCache\n");
}

void GetCurrentTransactionNestLevel(){
  printf("GetCurrentTransactionNestLevel\n");
}

void func_select_candidate(int, unsigned int*, _FuncCandidateList*){
  printf("func_select_candidate\n");
}

Oid TypenameGetTypid(char const*){
  printf("TypenameGetTypid\n");
  return InvalidOid;
}

void SystemAttributeByName(char const*, bool){
  printf("SystemAttributeByName\n");
}

void get_opclass_oid(unsigned int, List*, bool){
  printf("get_opclass_oid\n");
}

void simple_heap_delete(RelationData*, ItemPointerData*){
  printf("simple_heap_delete\n");
}

Oid LookupExplicitNamespace(char const*, bool){
  printf("LookupExplicitNamespace\n");
  return InvalidOid;
}

void CatalogUpdateIndexes(RelationData*, HeapTupleData*){
  printf("CatalogUpdateIndexes\n");
}

void get_database_name(unsigned int){
  printf("get_database_name\n");
}

void *stringToNode(char*){
  printf("stringToNode\n");
  return nullptr;
}

Relation heap_openrv_extended(RangeVar const*, int, bool){
  printf("heap_openrv_extended\n");
  Relation relation = palloc(sizeof(Relation));
  relation->rd_rel = palloc(sizeof(Form_pg_class));
  relation->rd_rel->relkind = RELKIND_RELATION;

  return relation;
}

SysScanDesc systable_beginscan(RelationData*, unsigned int, bool, SnapshotData*, int, ScanKeyData*){
  printf("systable_beginscan\n");
  return nullptr;
}

void get_range_subtype(unsigned int){
  printf("get_range_subtype\n");
}

void systable_endscan(SysScanDescData*){
  printf("systable_endscan\n");
}

void get_attnum(unsigned int, char const*){
  printf("get_attnum\n");
}

void get_base_element_type(unsigned int){
  printf("get_base_element_type\n");
}

void SearchSysCacheExists(int, unsigned long, unsigned long, unsigned long, unsigned long){
  printf("SearchSysCacheExists\n");
}

void type_is_enum(unsigned int){
  printf("type_is_enum\n");
}

void typeInheritsFrom(unsigned int, unsigned int){
  printf("typeInheritsFrom\n");
}

void get_func_signature(unsigned int, unsigned int**, int*){
  printf("get_func_signature\n");
}
