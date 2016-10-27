#include <binary_tree.h>

#include <stdlib.h> // for malloc

void main()
{
	
	Node *newnode = malloc(sizeof(Node));
	newnode->data = 5;

	Node *newnode2 = malloc(sizeof(Node));
	newnode2->data = 2;

	initializeTree(&newnode);

	newnode2->left_child = NULL;
	newnode2->right_child = NULL;

	if (addNodeUnbalanced(&newnode, newnode2))
	{
		printf("new node (2) added successfully!\n");
	}

	
	Node *newnode3 = malloc(sizeof(Node));
	newnode3->data = 4;

	if (addNodeUnbalanced(&newnode, newnode3))
	{
		printf("new node (4) added successfully!\n");
	}

	Node *newnode4 = malloc(sizeof(Node));
	newnode4->data = 11;

	if (addNodeUnbalanced(&newnode, newnode4))
	{
		printf("new node (11) added successfully!\n");
	}

	free(newnode);
	free(newnode2);
	free(newnode3);
	free(newnode4);
	
	return;
}
