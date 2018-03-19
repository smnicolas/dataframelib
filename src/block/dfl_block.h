#ifndef __DFL_BLOCK_H__
#define __DFL_BLOCK_H__
#include <stdlib.h>

typedef struct {
     size_t size;
     void * data;
} dfl_block;

dfl_block *dfl_block_alloc(const size_t size);
void dfl_block_realloc_duplicate_size(dfl_block * b);
#endif
