#ifndef __DFL_SERIES_H__
#define __DFL_SERIES_H__
#include <stdio.h>
#include <dfl/dfl_block.h>
#include <dfl/dfl_types.h>

typedef struct {
     dfl_basic_type type;
     size_t size;
     size_t stride;
     void * data;
     dfl_block *block;
     int owner;
} dfl_series;



dfl_series *dfl_series_alloc (dfl_basic_type btype,
                              size_t size,
                              size_t capacity);
dfl_series *dfl_series_read(dfl_basic_type btype, FILE * f);
void *dfl_series_min (dfl_series* s) ;

#endif
