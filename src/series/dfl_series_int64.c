#include <dfl/dfl_series.h>
#include <dfl/dfl_block.h>
#include <dfl/dfl_generics.h>
#include <stdlib.h>

void dfl_series_insert_tail_int64 (dfl_series* series, void *elem) {
     // TODO: check overflow
     dfl_series *s = series;
     if (s -> size * s -> stride >= s -> block -> size) {
          dfl_block_realloc_duplicate_size(s -> block);
     }
     int64_t * data = s -> data;
     data[s->size * s->stride] = *(int64_t*) elem;
     s->size ++;
}
