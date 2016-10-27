#include <ll.h>
#include <stdlib.h>
#include <mth_element.h>

void main()
{



	Element *head = malloc(sizeof(Element));

	int *five = malloc(sizeof(int));
	*five = (int)5;

	int *six = malloc(sizeof(int));
	*six = (int)6;

	Element *temp = malloc(sizeof(Element));

	head = NULL;


	// make a list of size 35 of the repeating pattern 5, 6, 5, 6, 5, 6 etc.
	for (int i = 0; i < 35; i++)
	{
		if(!push(&head, (void*)(i % 2 == 0 ? five : six)))
		{
			printf ("ERROR: Unable to initialize linked list; exiting\n");
			return;
		}
	}

	mth_element(&head, 5, &(temp->data));

	printf("fifth from last element: %d\n", (int)(*(int*)(temp->data)));

	printf("printing full list:");
	for (int i = 0; i < 35; i++)
	{
		pop(&head, &temp->data);
		printf("%d, ", (int)(*(int*)(temp->data)));
	}


	free(five);
	free(six);
	free(temp);


}
