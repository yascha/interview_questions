CC=gcc
CFLAGS=-I.
DEPS=node.h list_flatten.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

flatten_list: flatten_list.c test.c
	$(CC) -o flatten_list flatten_list.c test.c -I.
