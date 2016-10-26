#ifndef TREE_NODE_H
#define TREE_NODE_H


typedef struct Node
{
	struct Node *left_child;
	struct Node *right_child;
	int data;
} Node;


#endif // ifndef TREE_NODE_H
