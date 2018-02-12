#ifndef __DFL_SERIES_H__
#define __DFL_SERIES_H__
#include <stdio.h>
#include <dfl/dfl_block.h>

typedef struct {
     size_t size;
     size_t stride;
     void * data;
     dfl_block *block;
     int owner;
} dfl_series;

dfl_series *dfl_series_alloc (size_t size, size_t stride, size_t capacity);
#endif
