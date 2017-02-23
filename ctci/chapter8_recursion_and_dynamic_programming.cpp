/*
 * chapter8_recursion_and_dynamic_programming.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: Yascha
 */

#include <iostream>



using namespace std;

/*
 * 8.1 Triple step
 * A child running up a staircase with N steps can hop either 1, 2,
 * or 3 steps at a time.  Implement a method to count how many ways
 * the child can run up the stairs.
 */
unsigned int recursive_num_ways(unsigned int current_stair,
		unsigned int num_stairs);

unsigned int calc_triple_step(unsigned int num_stairs)
{
	return recursive_num_ways(0, num_stairs);
}


unsigned int recursive_num_ways(unsigned int current_stair, unsigned int num_stairs)
{
	unsigned int roll_up = 0;
	if (current_stair == num_stairs)
	{
		return roll_up;
	}
	else if (current_stair + 1 == num_stairs)
	{
		// we are one below the top stair, only one way up, return 1
		roll_up = 1;
		return roll_up;
	}
	else if (current_stair + 2 == num_stairs)
	{
		// we are 2 below the top stair, only 2 ways up (1-1, 2)
		roll_up = 2;
		return roll_up;
	}
	else if (current_stair + 3 == num_stairs)
	{
		// we are 3 below the top stair, only 4 ways up (1-2, 2-1, 1-1-1, 3)
		roll_up = 4;
		return roll_up;
	}
	else
	{
		// We aren't within 3 of the top, recursively calculate remaining ways
		roll_up += recursive_num_ways(current_stair+1, num_stairs);
		roll_up += recursive_num_ways(current_stair+2, num_stairs);
		roll_up += recursive_num_ways(current_stair+3, num_stairs);
		return roll_up;
	}

}


int main()
{
	unsigned int stairs = 5;
	unsigned int num_ways = calc_triple_step(stairs);
	cout << "There are " << num_ways << " ways to climb up "
			<< stairs << " stairs." << endl;

	return 0;
}
