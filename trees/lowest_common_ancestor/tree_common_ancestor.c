#include <tree_common_ancestor.h>

Node* findLowestCommonAncestor(Node* head, Node* first_child, Node* second_child)
{
	if ((first_child->data < head->data) &&  \
		(second_child->data < head->data))
	{
		if (head->left_child)
		{
			return findLowestCommonAncestor(head->left_child, first_child, second_child);
		}
		else
		{
			printf("ERROR: lowest common ancestor doesn't exist\n");
			return NULL;
		}
	}
	else if ((first_child->data > head->data) && \
		(second_child->data > head->data))
	{
		if (head->right_child)
		{
			return findLowestCommonAncestor(head->right_child, first_child, second_child);
		}
		else
		{
			printf("ERROR: lowest common ancestor doesn't exist\n");
			return NULL;
		}
	}
	else
	{
		// If the current value is between the first and second children
		// we are at the lowest common ancestor
		return head;
	}

}
