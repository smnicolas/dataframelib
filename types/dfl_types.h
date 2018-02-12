#ifndef __DFL_TYPES_H__
#define __DFL_TYPES_H__

typedef enum {
     dfl_type_bool,
     dfl_type_int64,
     dfl_type_double,
     dfl_type_string,
     dfl_basic_types_MAX = dfl_type_string
} dfl_basic_type;

typedef int (*dfl_int_func_void_const_void_const)
(void const *, void const *);

static void dfl_cmp_func_array_constructor ()
     __attribute__((constructor));
extern dfl_int_func_void_const_void_const
dfl_cmp_func_array[dfl_basic_types_MAX + 1];

#endif
