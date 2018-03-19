#include <stdlib.h>
#include <dfl/dfl_types.h>
#include <dfl/dfl_string.h>


static void dfl_type_size_constructor ()
     __attribute__((constructor));

void dfl_type_size_constructor() {
     dfl_type_size[dfl_type_bool] = sizeof(int);
     dfl_type_size[dfl_type_int64] = sizeof(int64_t);
     dfl_type_size[dfl_type_double] = sizeof(double);
     dfl_type_size[dfl_type_string] = sizeof(dfl_string);

}
