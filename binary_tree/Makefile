CC=gcc
CFLAGS=-I.
DEPS=tree_node.h binary_tree.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tree: binary_tree.c test.c
	$(CC) -o tree binary_tree.c test.c -I.
