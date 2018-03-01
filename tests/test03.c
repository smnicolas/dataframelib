#include <stdio.h>
#include <dfl/dfl_series.h>
#include <dfl/dfl_generics.h>
#include <dfl/dfl_types.h>


int main () {
     dfl_series *x;
     x = dfl_series_alloc(dfl_type_int64, 64, 1, 64);
     
     void *min = dfl_series_min(x);
     printf("min es: %ld\n", *(int64_t*)min);
     return 0;
}
