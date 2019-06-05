/* Copyright (C) 2005-2019 Shugo Maeda <shugo@ruby-lang.org> and Charlie Savage <cfis@savagexi.com>
   Please see the LICENSE file for copyright and distribution information */

#ifndef __RP_CALL_INFO_H__
#define __RP_CALL_INFO_H__

#include "rp_measure.h"
#include "rp_method.h"

extern VALUE cCallInfo;

/* Callers and callee information for a method. */
typedef struct prof_call_info_t
{
    prof_method_t *method;
    prof_method_t *parent;

    double total_time;
    double self_time;
    double wait_time;

    VALUE object;

    int called;

    unsigned int recursive : 1;
    unsigned int depth : 15;
    unsigned int line : 16;
} prof_call_info_t;

prof_call_info_t *prof_call_info_create(prof_method_t *method, prof_method_t *parent);
void prof_call_info_mark(prof_call_info_t *call_info);
prof_call_info_t *call_info_table_lookup(st_table* table, const prof_method_key_t* key);
size_t call_info_table_insert(st_table *table, const prof_method_key_t *key, prof_call_info_t *val);
prof_call_info_t* prof_get_call_info(VALUE self);
VALUE prof_call_info_wrap(prof_call_info_t* call_info);

void rp_init_call_info(void);

#endif //__RP_CALL_INFO_H__
