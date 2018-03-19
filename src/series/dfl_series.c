#include <dfl/dfl_series.h>
#include <dfl/dfl_block.h>
#include <dfl/dfl_generics.h>
#include <stdlib.h>

dfl_series *dfl_series_alloc (dfl_basic_type btype,
                              size_t size,
                              size_t capacity) {
     if (capacity < size) {
          fprintf(stderr,
                  "dfl_series_alloc: error size < capacity\n");
          abort ();
          
     }

     size_t stride = dfl_type_size[btype];
     dfl_block * block;
     dfl_series * s = malloc ( sizeof (dfl_series));
     if (s == 0) {
          free (s);
          fprintf(stderr,
                  "dfl_series_alloc: error con malloc\n");
                  abort ();
     }
     size_t nbytes = stride * capacity;
     if (nbytes / stride != capacity) {
          fprintf(stderr,
                  "dfl_series_alloc: overflow stride * capacity\n");
          abort ();
     }
     block = dfl_block_alloc (nbytes);

     if (block == 0) {
          free (block);
          fprintf(stderr,
                  "dfl_series_alloc: error with malloc\n");
          abort ();
     }
     s -> type = btype; 
     s -> size = size;
     s -> stride = stride;
     s -> data = block -> data;
     s -> owner = 1;
     return s;
}


void *dfl_series_min (dfl_series* s) {
     if (s -> size == 0) {
          fprintf(stderr, "zero length serie can't have min\n");
               abort ();
     }
     void * min = s -> data;
     for (int i = 1; i < s -> size; i++) {
          if (dfl_cmp_func_array[s->type](s -> data + i, min) < 0)
               min = s -> data + i;
     }
     return min;
}

dfl_series* dfl_series_from_array_int64(int64_t * arr, int len) {
     dfl_series s = dfl_series_alloc(dfl_type_int64, len, 4, len);
     for (int i = 0; i < len; i++) {
          dfl_series_insert_tail_int64 (s, arr[i]);
     }
     return s;
}

