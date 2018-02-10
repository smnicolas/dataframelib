#ifndef __DFL_STRING_H__
#define __DFL_STRING_H__

typedef struct {
     size_t len;
     uint8_t * data;
     dfl_block *block;
     int owner;
} dfl_string;

dfl_string *dfl_string_alloc (size_t size, size_t capacity);
#endif
