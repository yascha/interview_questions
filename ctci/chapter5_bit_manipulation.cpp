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

