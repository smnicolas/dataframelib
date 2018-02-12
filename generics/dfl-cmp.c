#include <stdio.h>
#include <stdlib.h>
#include <unistr.h>
#include <dfl/dfl_types.h>
#include <dfl/dfl_block.h>
#include <dfl/dfl_string.h>

int dfl_int64_cmp(void const *a, void const *b) {
     return (*(int64_t*)a) - (*(int64_t*)b);
}

int dfl_double_cmp(void const *a, void const *b) {
     double ad = *(double*)a;
     double bd = *(double*)b;
     if (ad < bd)
          return -1;
     else if (ad > bd)
          return 1;
     else
          return 0;
}

int dfl_string_cmp(void const *a, void const *b) {
     dfl_string * as = (dfl_string *)a;
     dfl_string * bs = (dfl_string *)b;
     return u8_cmp2(as -> data, as -> len, bs -> data, bs -> len);
}

int
not_implemented_func_int_const_void_const_void (
     void const *a, void const *b) {
     fprintf(stderr,"function not implemented\n");
     abort ();
     return 0;
}

dfl_int_func_void_const_void_const
dfl_cmp_func_array[dfl_basic_types_MAX + 1];

void dfl_cmp_func_array_constructor () {
     dfl_cmp_func_array[dfl_type_bool] =
          not_implemented_func_int_const_void_const_void;
     dfl_cmp_func_array[dfl_type_int64] = dfl_int64_cmp;
     dfl_cmp_func_array[dfl_type_double] = dfl_double_cmp;
     dfl_cmp_func_array[dfl_type_string] = dfl_string_cmp;
}

