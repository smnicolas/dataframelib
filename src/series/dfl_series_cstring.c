#include <dfl/dfl_series.h>
#include <dfl/dfl_block.h>
#include <dfl/dfl_generics.h>
#include <stdlib.h>

void dfl_series_insert_tail_cstring (dfl_series* s, void *elem) {
     // TODO: check overflow
     if (s -> size * s -> stride >= s -> block -> size) {
          dfl_block_realloc_duplicate_size(s);
     }
     
     s->data[s->size * s->stride] = (char *) strdup(elem);
     s->size ++;
}
