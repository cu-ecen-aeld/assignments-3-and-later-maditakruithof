CC := gcc

ifdef CROSS_COMPILE
	CC := $(CROSS_COMPILE)gcc
endif

all: writer.c
	$(CC) writer.c -o writer

clean:
	rm -f writer