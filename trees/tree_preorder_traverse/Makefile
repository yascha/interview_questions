CC=gcc
CFLAGS=-I.
DEPS=tree_node.h binary_tree.h tree_preorder.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tree_preorder: binary_tree.c test.c tree_preorder.c
	$(CC) -o tree_preorder binary_tree.c tree_preorder.c test.c -I.
