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
