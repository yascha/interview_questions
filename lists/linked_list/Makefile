CC=gcc
CFLAGS=-I.
DEPS=stack.h ll.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ll_test: ll.c test.c stack.c
	$(CC) -o ll_test ll.c test.c stack.c -I.
