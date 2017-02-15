/*
 * chapter5_bit_manipulation.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: Yascha
 */

/*
 * chapter5_bit_manipulation.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: Yascha
 */

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

/*
 * 5.1 Insertion
 * Given 2 32bit numbers N and M and two bit positions i and j,
 * write a method to insert M into N such that M starts at bit j
 * and ends at bit i.  You can assume that the bits j to i have
 * enough space to fit all of M.
 * ie. input N = 10000000000, M = 1011, i = 2, j = 6
 * output N = 10001001100
 */

unsigned int insert_m_into_n(unsigned int n, unsigned int m,
		unsigned int i, unsigned int j)
{
	unsigned int result;

	// make a mask of all 1s, but with 0s from the i to j positions
	unsigned int mask = 1;
	for (unsigned int x = 0; x < j - m; x++)
	{
		mask |= 1;
		mask <<= 1;
	}

	mask <<= i;
	mask = ~mask;

	// zero out from i to j
	result = n&mask;

	// now shift m and add it to that spot
	result |= (m << j);

	return result;
}


/*
 * 5.3 Flip bit to win
 * You have an integer and you can flip exactly one bit from a 0 to a 1.
 *  Write code to find the length of the longest sequence of 1s you could
 *  create.
 *  ie. input 1775 (11011101111)
 *  output 8 (the size of the longest sequence of 1s, not the index to flip)
 */
int flip_bit_to_win(int input)
{
	int result = 0;

	list<int> l;

	if (input&1)
	{
		l.push_back(-1);
	}

	int j = 0;

	while (j < 32)
	{
		if (!(input&1))
		{
			l.push_back(j);
		}
		input >>= 1;
		j++;
	}

	/* Now we have a list of all of the zero locations
	 we can use it to calculate the longest sequence

	 The largest sequence is equal to the largest difference between two
	 indexes that are exactly 1 index away (the index in the middle of
	 them corresponds to the zero that we turn into a 1).


	 It is easiest to show this with an example:
	 Take the number 52090 (0000 1100 1011 0111 1010)
	 We can see that the zeros are positioned (with 0 being the far right)
	 in indices 0, 2, 7, 10, 12, etc.
	 The largest sequence is size 7 and is from 7 -> 0 (we flip the zero
	 in position 2)

	The only caveat of this is that we need to make sure we initialize our
	list with a -1 value in the case that the 0th digit is not a 0 because
	the solution may start at the very beginning.  You can see we did that
	on line 74.
	*/

	cout << "(zero-based) zero indexes = ";
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));


	list<int>::const_iterator front_iterator = l.begin();
	front_iterator++;
	front_iterator++;

	list<int>::const_iterator rear_iterator = l.begin();

	while (front_iterator != l.end())
	{
		if (*front_iterator - 1 - *rear_iterator > result)
		{
			result = *front_iterator - *rear_iterator - 1;
		}
		front_iterator++;
		rear_iterator++;
	}

	return result;

}



int test_flip_bit_to_win()
{
	int input = 1529813;
	int max_sequence_size = flip_bit_to_win(input);
	cout << endl << "Max sequence size for " << input << " = "
			<< max_sequence_size << endl;
	return 0;
}

