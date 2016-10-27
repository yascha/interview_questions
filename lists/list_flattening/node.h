#ifndef NODE_H
#define NODE_H

typedef struct Node
{
	struct Node *next;
	struct Node *prev;
	struct Node *child;
	int          value;
} Node;

#endif // ifndef NODE_H
