#include <dfl/dfl_string.h>

dfl_string *dfl_string_alloc (size_t size, size_t capacity) {
     if (capacity < size) {
          fprintf(stderr,
                  "dfl_string_alloc: error size < capacity\n");
          abort ();
     }
     dfl_block * block;
     dfl_string * s = malloc ( sizeof (dfl_string));
     if (s == 0) {
          free (s);
          fprintf(stderr,
                  "dfl_string_alloc: error con malloc\n");
                  abort ();
     }

     block = dfl_block_alloc (capacity);

     if (block == 0) {
          free (block);
          fprintf(stderr,
                  "dfl_series_alloc: error with malloc\n");
          abort ();
     }
     s -> len = 0;
     s -> data = block -> data;
     s -> owner = 1;
     return s;
}
