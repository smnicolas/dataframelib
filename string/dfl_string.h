#ifndef __DFL_STRING_H__
#define __DFL_STRING_H__

typedef struct {
     size_t size;
     void * data;
     dfl_block *block;
     int owner;
} dfl_string;

dfl_series *dfl_string_alloc (size_t size);
#endif
