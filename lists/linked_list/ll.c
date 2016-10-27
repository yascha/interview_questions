#include <ll.h>


bool push (Element **stack, void *data)
{

	Element *elem = malloc (sizeof(Element));

	if (!elem)
	{
		// return false if the malloc failed
		return false;
	}

	// update our new element
	elem->data = data;

	if (stack)
	{
		elem->next = *stack;
	}
	else
	{
		elem->next = NULL;
	}

	// set the stack pointer to our element (it is the new head)
	*stack = elem;

	return true;


}

bool pop (Element **stack, void **data)
{

	// if we got passed a null pointer, return false
	if (!stack)
	{
		return false;
	}

	// prepare the return data
	*data = (*stack)->data;

	// remove the old head and update the stack pointer
	// use a temporary pointer so that we don't lose track of head
	// and so we can free it
	Element *elem = *stack;
	*stack = elem->next;
	free(elem);
	return true;

}



