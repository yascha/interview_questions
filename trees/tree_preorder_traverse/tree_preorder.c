#include <tree_preorder.h>
#include <stdio.h>

void preorderTraverse (Node *head)
{
	printf("%d, ", head->data);
	if (head->left_child)
	{
		preorderTraverse(head->left_child);
	}
	if (head->right_child)
	{
		preorderTraverse(head->right_child);
	}
	return;
}

