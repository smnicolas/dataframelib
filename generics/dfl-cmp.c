int dfl_int64_cmp(void *a, void *b) {
     return ((int64)*a) - ((int64)*b);
}

int dfl_double_cmp(void *a, void *b) {
     double ad = *a;
     double bd = *b;
     if (ad < bd)
          return -1;
     else if (ad > bd)
          return 1;
     else
          return 0;
}

int dfl_string_cmp(void *a, void *b) {
     char * as = *a;
     char * bs = *b;
     return strcmp(as, bs);
}

int not_implemented(void *a, void *b) {
     fprintf(stderr,"function not implemented\n");
     abort ();
     return 0;
}
int (*dfl_cmp_switch[dfl_ntypes]) (void*, void*) = { 0, 0, 0, 0 };

dfl_cmp_switch[dfl_int64] = dfl_int64_cmp;
dfl_cmp_switch[dfl_double] = dfl_double_cmp;
dfl_cmp_switch[dfl_string] = dfl_string_cmp;




