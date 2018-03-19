#ifndef __DFL_TYPES_H__
#define __DFL_TYPES_H__

typedef enum {
     dfl_type_bool,
     dfl_type_int64,
     dfl_type_double,
     dfl_type_string,
     dfl_type_cstring,
     dfl_basic_types_MAX = dfl_type_cstring
} dfl_basic_type;

extern size_t dfl_type_size[dfl_basic_types_MAX + 1];


#endif
