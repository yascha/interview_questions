CC=gcc
CFLAGS=-I.
DEPS=stack.h ll.h mth_element.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mth_ll: ll.c test.c stack.c
	$(CC) -o mth_ll mth_element.c ll.c test.c stack.c -I.
