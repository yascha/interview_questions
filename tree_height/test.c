#include <binary_tree.h>
#include <tree_height.h>

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
	newnode3->left_child = NULL;
	newnode3->right_child = NULL;

	if (addNodeUnbalanced(&newnode, newnode3))
	{
		printf("new node (4) added successfully!\n");
	}

	Node *newnode4 = malloc(sizeof(Node));
	newnode4->data = 11;
	newnode4->left_child = NULL;
	newnode4->right_child = NULL;

	if (addNodeUnbalanced(&newnode, newnode4))
	{
		printf("new node (11) added successfully!\n");
	}


	printf("Tree height = %d (should be %d)\n", getMaxTreeHeight(newnode), 3);

	Node *newnode5 = malloc(sizeof(Node));
	newnode5->data = 6;
	newnode5->left_child = NULL;
	newnode5->right_child = NULL;

	if (addNodeUnbalanced(&newnode, newnode5))
	{
		printf("new node (6) added successfully!\n");
	}

	printf("Tree height = %d (should be %d)\n", getMaxTreeHeight(newnode), 3);

	Node *newnode6 = malloc(sizeof(Node));
	newnode6->data = 3;
	newnode6->left_child = NULL;
	newnode6->right_child = NULL;

	if (addNodeUnbalanced(&newnode, newnode6))
	{
		printf("new node (3) added successfully!\n");
	}

	printf("Tree height = %d (should be %d)\n", getMaxTreeHeight(newnode), 4);

	free(newnode);
	free(newnode2);
	free(newnode3);
	free(newnode4);
	free(newnode5);
	free(newnode6);
	
	return;
}
