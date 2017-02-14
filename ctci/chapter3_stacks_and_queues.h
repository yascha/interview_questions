/*
 * chapter3_stacks_and_queues.h
 *
 *  Created on: Feb 14, 2017
 *      Author: Yascha
 */

#ifndef CHAPTER3_STACKS_AND_QUEUES_H_
#define CHAPTER3_STACKS_AND_QUEUES_H_

#include <iostream> // for string
#include <cstddef> // for NULL
#include <stdlib.h> // for free
#include <utility> // for pair
#include <vector> // for vector
#include <memory> // for allocator
#include <list> // for list
#include <iterator> // for cost_iterator

enum AnimalType {DOG, CAT, MAX_ANIMAL_TYPE};

class Animal
{
	private:
		std::pair<int, std::string> animal;

	public:
		Animal()
		{
			animal = std::pair<int, std::string>(MAX_ANIMAL_TYPE, std::string());

		}
		explicit Animal(AnimalType type, const std::string& name)
		{
			animal = std::pair<int, std::string>(type, name);
		}

		~Animal()
		{
		}

		AnimalType get_type()
		{
			return ((AnimalType)((this->animal).first));
		}

		std::string get_name()
		{
			return this->animal.second;
		}

};

class Shelter
{
	private:
		std::list<Animal> animals;
		std::list<Animal>::iterator next_cat, next_dog;

		void update_next_dog();
		void update_next_cat();

	public:
		Shelter()
		{
			animals = std::list<Animal>();
			next_cat = next_dog = animals.end();
		}


		void enqueue(Animal animal);

		Animal dequeueAny();
		Animal dequeueDog();
		Animal dequeueCat();
};



#endif /* CHAPTER3_STACKS_AND_QUEUES_H_ */
