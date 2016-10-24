#include <ll.h>
#include <stdlib.h>

void main()
{

	Element *head = malloc(sizeof(Element));

	int *five = malloc (sizeof(int));
	*five = (int)5;

	int *six = malloc (sizeof(int));
	*six = (int)6;

	printf("five is %d\n", *five);
	
	if(push(&head, (void*)five))
	{
		printf ("head created successfully\n");
	}
	else
	{
		printf ("unable to malloc head\n");
	}

	printf("head is %d (should be 5)\n", *((int*)(head->data)));

	push(&head, (void*)six);

	printf("head is %d (should be 6)\n", *((int*)(head->data)));

	Element *temp = malloc(sizeof(Element));


	pop(&head, &temp->data);

	printf("head is %d (should be 5 again)\n", *((int*)(head->data)));
	printf("popped value was %d (should be 6)\n", *((int*)(temp->data)));

	free(five);
	free(head);
	free(six);
	free(temp);


}
