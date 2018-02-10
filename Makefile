INCLUDE_DIR=$(HOME)/include/dfl
dfl-includes:
	cp block/dfl_block.h string/dfl_string.h series/dfl_series.h \
	types/dfl_types.h \
	$(INCLUDE_DIR)

