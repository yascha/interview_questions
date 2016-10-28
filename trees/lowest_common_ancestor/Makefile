CC=gcc
CFLAGS=-I.
DEPS=tree_node.h binary_tree.h tree_common_ancestor.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tree_ancestor: binary_tree.c test.c tree_common_ancestor.c
	$(CC) -o tree_ancestor binary_tree.c tree_common_ancestor.c test.c -I.
