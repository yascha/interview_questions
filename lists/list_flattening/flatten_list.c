#include <stdio.h>
#include <flatten_list.h>
#include <node.h>

void flatten_list(Node *head, Node **tail)
{
	Node *current_node = head;
	
	
	// put the children of each node to the end until we have flattened the list
	while(current_node != NULL)
	{
		if (current_node->child)
		{
			(*tail)->next = current_node->child;
			current_node->prev = *tail;

			// we have to iterate through the child list now to find our new tail
			Node *temp_node = current_node->child;
			while (temp_node->next != NULL)
			{
				// do nothing, we just want temp_node to be the last node
			}
			*tail = temp_node;

		}
		current_node = current_node->next;
	}

	
}
