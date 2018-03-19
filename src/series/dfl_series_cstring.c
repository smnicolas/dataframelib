#include <dfl/dfl_series.h>
#include <dfl/dfl_block.h>
#include <dfl/dfl_generics.h>
#include <stdlib.h>
#include <string.h>
void dfl_series_insert_tail_cstring (dfl_series* serie, void *elem) {
     // TODO: check overflow
     dfl_series * s = serie;
     if (s -> size * s -> stride >= s -> block -> size) {
          dfl_block_realloc_duplicate_size(s -> block);
     }

     char** data = s -> data;
     data[s->size * s->stride] = (char *) strdup((char *)elem);
     s->size ++;
}
