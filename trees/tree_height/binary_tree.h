#include <tree_node.h>
#include <stdbool.h>

#include <stdio.h>

bool addNodeUnbalanced(Node** head, Node* new_node);

bool removeNodeUnbalanced(Node** head, Node* node_to_remove);


bool initializeTree(Node** head);

static Node* findSmallerLeftChild(Node* subtree, int data);
static Node* findBiggerRightChild(Node* subtree, int data);

// for debugging only
void printTree(Node** head);

