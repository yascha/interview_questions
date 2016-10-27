CC=gcc
CFLAGS=-I.
DEPS=tree_node.h binary_tree.h tree_height.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tree_height: binary_tree.c test.c tree_height.c
	$(CC) -o tree_height binary_tree.c tree_height.c test.c -I.
