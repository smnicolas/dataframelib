#include <stdio.h>
#include <dfl/dfl_series.h>
#include <dfl/dfl_generics.h>
#include <dfl/dfl_types.h>


int main () {
     dfl_series *x;
     x = dfl_series_alloc(64, 1, 64);

     int64_t i0, i1;
     i0 = 1; i1 = 9;
     printf ("i0: %ld, i1: %ld. cmp: %d\n", i0, i1,
             dfl_cmp_func_array[dfl_type_int64](&i0, &i1));

     printf ("i0: %ld, i0: %ld. cmp: %d\n", i0, i0,
             dfl_cmp_func_array[dfl_type_int64](&i0, &i0));

     printf ("i1: %ld, i0: %ld. cmp: %d\n", i1, i0,
             dfl_cmp_func_array[dfl_type_int64](&i1, &i0));

     printf ("i1: %ld, i0: %ld. cmp: %d\n", i1, i0,
             dfl_cmp_func_array[dfl_type_bool](&i1, &i0));
     
     return 0;
}
