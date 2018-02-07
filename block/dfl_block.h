#ifndef __DFL_BLOCK_H__
#define __DFL_BLOCK_H__

typedef struct {
     size_t size;
     void * data;
} dfl_block;

dfl_block *dfl_block_alloc(const size_t size);

#endif
