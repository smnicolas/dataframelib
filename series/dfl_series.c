#include <dfl/dfl_series.h>
#include <dfl/dfl_block.h>
#include <stdlib.h>

dfl_series *dfl_series_alloc (size_t size, size_t stride, size_t capacity) {
     if (capacity < size) {
          fprintf(stderr,
                  "dfl_series_alloc: error size < capacity\n");
          abort ();
          
     }
     if (stride == 0) {
          fprintf(stderr,
                  "dfl_series_alloc: error stride == 0\n");
          abort ();

     }
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
     s -> size = size;
     s -> stride = stride;
     s -> data = block -> data;
     s -> owner = 1;
     return s;
}

