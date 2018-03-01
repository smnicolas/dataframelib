INCLUDE_DIR=$(HOME)/include

CC = gcc
CFLAGS = -c -Wall -g -Os -I$(INCLUDE_DIR)
LD = $(CC)
#LDFLAGS = -lfoo

TARGET = libdfl.a

OBJECTS = $(patsubst %.c, %.o, $(shell find src -name "*.c"))

all: $(TARGET)

$(TARGET): dfl-includes $(OBJECTS)
	ar rcs $(HOME)/lib/$@ build/*.o 



#$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o build/$(notdir $@)

include-dir:
	mkdir $(INCLUDE_DIR)
dfl-includes:
	find $(INCLUDE_DIR)/dfl -type f -name "*.h" -exec rm {} \; && \
	find -type f -name "dfl_*.h" -exec cp {} $(INCLUDE_DIR)/dfl \; 

clean:
	$(cd build && rm $(TARGET) $(OBJECTS))

