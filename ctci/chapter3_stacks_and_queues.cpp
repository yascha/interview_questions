/*
 * chapter3_stacks_and_queues.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: Yascha
 */

/*
 * chapter3_stacks_and_queues.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: Yascha
 */

#include "chapter3_stacks_and_queues.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <climits>

// Chapter 3

using namespace std;


/*
 * 3.2 Stack Min
 * Implement a stack that supports a O(1) min() function.
 * Needs to support: push(), pop(), and min()
 */


bool MinStack::push(int data)
{
	Node* temp = new Node;
	if (!temp)
	{
		return false;
	}

	if (head != NULL)
	{
		temp->next = head;
	}
	else
	{
		temp->next = NULL;
	}

	temp->data = data;

	if (data < min)
	{
		min = data;
	}

	head = temp;
	return true;
}

int MinStack::pop()
{
	int returnValue;

	// Return -1 if we haven't been initialized
	Node* temp = head;
	if (!temp)
	{
		return -1;
	}

	// Get the return data from head, update head, free head
	returnValue = head->data;
	head = head->next;
	free(temp);

	// update min if necessary
	if (returnValue == min)
	{
		updateMin();
	}

	return returnValue;
}

void MinStack::updateMin()
{
	int currentMin = INT_MAX;
	while(head != NULL)
	{
		if (head->data < currentMin)
		{
			currentMin = head->data;
		}
		head = head->next;
	}
	min = currentMin;
}

void MinStack::printMin()
{
	cout << min << endl;
}


int test_minstack()
{
	MinStack m;
	m.printMin();

	m.push(5);
	m.printMin();


	m.push(3);
	m.printMin();

	m.pop();
	m.printMin();

	return 0;
}




/*
 * 3.6 Animal Shelter
 * An animal shelter, which holds only dogs and cats, operates
 * on a strictly "first in, first out" basis.  People must adopt
 * either the "oldest" (based on arrival time) of all animals at
 * the shelter, or they can select whether they would prefer a dog
 * or a cat (and will receive the oldest animal of that type). They
 * cannot select which specific animal they would like.  Create the
 * data structures to maintain this system and implement operations
 * such as:
 * enqueue
 * dequeueAny
 * dequeueDog
 * dequeueCat
 */



void Shelter::update_next_dog()
{
	std::list<Animal>::iterator i = animals.begin();
	while ((*i).get_type() != DOG && i != animals.end())
	{
		i++;
	}
	next_dog = i;
}

void Shelter::update_next_cat()
{
	std::list<Animal>::iterator i = animals.begin();
	while ((*i).get_type() != CAT && i != animals.end())
	{
		i++;
	}
	next_cat = i;
}


void Shelter::enqueue(Animal animal)
{
	AnimalType type = animal.get_type();

	animals.push_back(animal);

	if (type == DOG)
	{
		update_next_dog();
	}
	else if (type == CAT)
	{
		update_next_cat();
	}
}


Animal Shelter::dequeueAny()
{
	Animal returnval = *(animals.begin());
	animals.pop_front();

	// update next cat or dog
	if (returnval.get_type() == DOG)
	{
		update_next_dog();
	}
	else if (returnval.get_type() == CAT)
	{
		update_next_cat();
	}

	return returnval;
}

Animal Shelter::dequeueDog()
{
	Animal returnval = *next_dog;


	animals.erase(next_dog);

	// update next dog
	if (returnval.get_type() == DOG)
	{
		update_next_dog();
	}

	return returnval;
}

Animal Shelter::dequeueCat()
{
	Animal returnval = *next_cat;


	animals.erase(next_cat);

	// update next dog
	if (returnval.get_type() == CAT)
	{
		update_next_cat();
	}

	return returnval;
}





int test_animal_shelter()
{
	Shelter shel;
	Animal bob = Animal(DOG, "bob");
	Animal john = Animal(CAT, "john");
	Animal suzy = Animal(CAT, "suzy");
	Animal digs = Animal(DOG, "diggity");

	shel.enqueue(bob);
	shel.enqueue(john);
	shel.enqueue(suzy);
	shel.enqueue(digs);

	Animal temp = shel.dequeueCat();
	cout << temp.get_name() << endl;
	temp = shel.dequeueCat();
	cout << temp.get_name() << endl;
	temp = shel.dequeueDog();
	cout << temp.get_name() << endl;
	temp = shel.dequeueDog();
	cout << temp.get_name() << endl;

	return 0;
}
