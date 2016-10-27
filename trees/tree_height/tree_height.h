#include <tree_node.h>
#include <binary_tree.h>

int getMaxTreeHeight(Node *head);


static int getSubTreeHeight(Node *head, int current_height);
