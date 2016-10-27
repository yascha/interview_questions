#include <binary_tree.h>


bool addNodeUnbalanced(Node** head, Node* new_node)
{

	// validate inputs
	if (!head || !new_node)
	{
		return false;
	}

	Node *current_node = *head;
	int new_node_value = new_node->data;
	
	if (new_node_value > current_node->data)
	{
		if (current_node->right_child)
		{
			// If there is a right child, find our new parent and add ourselves
			current_node = findBiggerRightChild(current_node, new_node_value);

			// If our new child is bigger than us, it becomes a right child
			if (current_node->right_child->data > new_node_value)
			{
				new_node->right_child = current_node->right_child;
				current_node->right_child = new_node;
			}
			else
			{
				// otherwise it is smaller than us and is a left child
				new_node->left_child = current_node->right_child;
				current_node->right_child = new_node;
			}
		}
		else
		{
			// if there is no child, then we can just be the new right child
			current_node->right_child = new_node;
			return true;
		}
	}
	else if (new_node_value < current_node->data)
	{
		if (current_node->left_child)
		{
			// if there's a left child, find our new parent and add ourselves
			current_node = findSmallerLeftChild(current_node, new_node_value);

			// if our new child is smaller than us, it becomes a left child
			if (current_node->left_child->data < new_node_value)
			{
				new_node->left_child = current_node->left_child;
				current_node->left_child = new_node;
			}
			else
			{
				// otherwise it is bigger than us and is a right child
				new_node->right_child = current_node->left_child;
				current_node->left_child = new_node;
			}
		}
		else
		{
			// if there is no left child, then we can be the new left child
			current_node->left_child = new_node;
		}
	}
	else
	{
		// received a value matching the root node
		printf("ERROR: received duplicate value\n");
		return false;
	}
	return true;
}


bool removeNodeUnbalanced(Node** head, Node* node_to_remove)
{
	return true;
}


// find a smaller left child node in the given subtree (if one exists)
// return the smallest left child node if one doesn't exist
// assume that the node of the subtree that is being passed has already been inspected (just check the child)
static Node* findSmallerLeftChild(Node* subtree, int data)
{
	// if there is no left child, return this node; it will be the parent of the new node
	if (!subtree->left_child)
	{
		return subtree;
	}
	// If I'm smaller than the left child node, keep going
	if (subtree->left_child->data > data)
	{
		return findSmallerLeftChild(subtree->left_child, data);
	}
	// If I'm bigger than the left child, it will be my new child and I'll take it's place
	else if (subtree->left_child->data < data)
	{
		return subtree;
	}
	else
	{
		printf("ERROR: value matches a node in the tree, cannot add to binary tree\n");
		return NULL;
	}
}


// find a bigger right child node in the given subtree if one exists
// return the largest right child node if one doesn't exist
static Node* findBiggerRightChild(Node* subtree, int data)
{

	// if there is no right child, return this node; it will be the parent of the new node
	if (subtree->right_child)
	{
		return subtree;
	}
	// If I'm larger than the right child, keep going deeper
	if (subtree->right_child->data < data)
	{
		return findBiggerRightChild(subtree->right_child, data);
	}
	// If I'm smaller than the right child, it will be my new child and I'll take it's place
	else if (subtree->right_child->data > data)
	{
		return subtree;
	}
	else
	{
		printf("ERROR: value matches a node in the tree, cannot add to binary tree\n");
		return NULL;
	}
}


bool initializeTree(Node** head)
{
	(*head)->left_child = NULL;
	(*head)->right_child = NULL;

	return true;
}

