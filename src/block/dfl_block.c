#include <stdlib.h>
#include <stdio.h>

#include <dfl/dfl_block.h>

dfl_block *dfl_block_alloc(const size_t size) {

     dfl_block *b;
     b = (dfl_block *) malloc (sizeof (dfl_block));
     if (b == 0) {
          fprintf (stderr, "failure allocatting memory for block struct\n");
          abort ();
     }

     b -> data = malloc ( size );
     if (b -> data == 0 && size > 0) {
          free (b);
          fprintf (stderr, "failure allocatting memory for block struct data\n");
          abort ();
     }
     b -> size = size;
     return b;
}

void dfl_block_realloc_duplicate_size(dfl_block * b) {
     size_t newsize = b -> size * 2;
     void * newdata =  realloc (b -> data, newsize);
     if (newdata == 0) {
          fprintf (stderr, "failure reallocatting memory for block struct\n");
          abort ();
     }
     
     b -> data = newdata;
     b -> size = newsize;
}
