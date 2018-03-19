#ifndef __DFL_GENERICS_H__
#define __DFL_GENERICS_H__

#include <dfl/dfl_types.h>
#include <dfl/dfl_series.h>

int dfl_cmp (dfl_basic_type type, void const *a, void const *b);

typedef int (*dfl_int_func_void_const_void_const)
(void const *, void const *);

typedef dfl_series* (*dfl_series_func_btype_FILE)
     (dfl_basic_type btype, FILE * f);

extern dfl_int_func_void_const_void_const
dfl_cmp_func_array[dfl_basic_types_MAX + 1];

extern dfl_series_func_btype_FILE
dfl_series_read_func_array[dfl_basic_types_MAX + 1];
#endif
