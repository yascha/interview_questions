#include <mth_element.h>
#include <stdio.h>


bool mth_element(Element **head, int m, void **data)
{
	// check that we received a valid head
	if (!head || !*head)
	{
		printf("invalid head received\n");
		return false;
	}


	// create two pointers to use to traverse the list
	Element *first = malloc(sizeof(Element));
	Element *trailing = malloc(sizeof(Element));

	int current_offset = 0;

	// these are just for debugging correctness
	int front_pointer_place_in_list = 0;
	int back_pointer_place_in_list = 0;

	// both pointers start at the head of the list
	first = *head;
	trailing = *head;


	// iterate until first hits the end of the list (denoted by elem->next = NULL)
	// and then return the value of trailing
	while (first->next != NULL)
	{
//		printf("front pointer place in list = %d; current data = %d\n", front_pointer_place_in_list, (int)*((int*)(first->data)));
//		printf("back pointer place in list = %d\n", back_pointer_place_in_list);
		first = first->next;
		front_pointer_place_in_list++;

		// update the trailing pointer if we've iterated m times
		// otherwise keep counting up to m
		if (current_offset < m)
		{
			current_offset++;
		}
		else
		{
			trailing = trailing->next;
			back_pointer_place_in_list++;
		}
	}


	// catch the special case where m = 0 and return the last item
	if (m == 0)
	{
		*data = first->data;
	}
	// if the list was smaller than the offset, return false
	else if (current_offset < m)
	{
		printf("ERROR: m was smaller than the size of the list\n");
		return false;
	}
	// otherwise this is the base condition; return the mth-to-last item in the data param
	else
	{
		*data = trailing->data;
	}



}
