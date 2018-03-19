#include "<dfl/dfl_generics.h>"

static void dfl_series_read_func_array_constructor ()
     __attribute__((constructor));


int
not_implemented_func_series_btype_FILE (
     dfl_basic_type btype, FILE * f) {
     fprintf(stderr,"function not implemented\n");
     abort ();
     return 0;
}

dfl_series * dfl_series_read_int(char *string) { 

     int sum = 0;
     dfl_series_read_int * series;
     dfl_series_alloc(series);
     while (1) {
          char *tail;
          int next;

          while (isspace (*string)) string++;
          if (*string == 0)
               break;

          errno = 0;
          next = strtol (string, &tail, 0);
          if (errno)
               printf ("Overflow\n");
          else
               sum += next;
          string = tail;
     }

          return sum;
     }

     
}

dfl_int_func_void_const_void_const
dfl_series_read_func_array[dfl_basic_types_MAX + 1];

void dfl_series_read_func_array_constructor () {
     dfl_series_read_func_array[dfl_type_bool] =
          not_implemented_func_series_btype_FILE;
     dfl_series_read_func_array[dfl_type_int64] =
          not_implemented_func_series_btype_FILE;
     dfl_series_read_func_array[dfl_type_double] =
          not_implemented_func_series_btype_FILE;
     dfl_series_read_func_array[dfl_type_string] =
          not_implemented_func_series_btype_FILE;
}


dfl_series *dfl_series_read(dfl_basic_type btype, FILE * f) {
     return dfl_series_read_func_array[type](a, b);     
}
