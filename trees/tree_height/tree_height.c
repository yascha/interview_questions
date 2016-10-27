#include <tree_height.h>

// Return the max height of the binary tree provided
// If the tree is not valid, return -1
int getMaxTreeHeight(Node *head)
{
	return getSubTreeHeight(head, 1);
}


static int getSubTreeHeight(Node *head, int current_height)
{

	// we could reduce RAM usage by not storing the inter-sub-tree heights here, but I think
	// it is easier to read this way, which makes the code easier to maintain
	int left_sub_tree_height = current_height;
	int right_sub_tree_height = current_height;
	
	if (head->left_child)
	{
		left_sub_tree_height = getSubTreeHeight(head->left_child, current_height+1);
	}
	if (head->right_child)
	{
		right_sub_tree_height = getSubTreeHeight(head->right_child, current_height+1);
	}

	return (left_sub_tree_height > right_sub_tree_height ? left_sub_tree_height : right_sub_tree_height);
	
}

