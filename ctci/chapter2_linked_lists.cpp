/*
 * chapter2_linked_lists.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: Yascha
 */

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <algorithm>

// Chapter 2

using namespace std;


/*
 * 2.1 Remove Dups
 * Write code to remove duplicates from an unsorted linked list.
 */

/*
 * Approach:
 * Iterate once through the list, keeping track of each piece of data
 * that we have seen.  If we see it again, remove it and continue
 * through the list.
 *
 * Note that we could do this very trivially with remove_if from the STL.
 */

bool remove_dups(list<int>& head)
{
	map<int,int> data_map;
	list<int>::iterator iter = head.begin();

	while (iter != head.end())
	{
		data_map[*iter] += 1;
		if (data_map[*iter] > 1)
		{
			head.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	return true;
}


int test_remove_dups()
{
	//int my_list[] = {6, 4, 3, 7, 98, 9, 9, 9, 6, 4};
	//list<int> test_list (my_list, my_list + sizeof(my_list) / sizeof(int));

	list<int> test_list (4, 100);

	cout << "original list: ";
	list<int>::const_iterator i;
	for (i = test_list.begin(); i != test_list.end(); i++)
	{
		cout << *i << ", ";
	}
	cout << endl;

	remove_dups(test_list);

	cout << "removed dups list: ";
	list<int>::const_iterator j;
	for (i = test_list.begin(); j != test_list.end(); j++)
	{
		cout << *j;
	}
	return 0;
}


/*
 * 2.2 Kth to last
 * Implement an algorithm to return the kth to last element of a singly
 * linked list.
 */
int kth_to_last(unsigned int k, const list<int>& l)
{
	if (k > l.size())
	{
		// can't return kth to last if the list isn't at least size k
		return -1;
	}

	list<int>::const_reverse_iterator iter = l.rbegin();
	unsigned int j = 0;
	while (iter != l.rend())
	{
		j++;
		iter++;
		if (j == k)
		{
			return *iter;
		}
	}
	return -1;
}


int test_kth_to_last()
{

	list<int> mylist (100, 5);
	cout << kth_to_last(3, mylist);
	return 0;
}


/*
 * 2.4 Partition
 * Write code to partition a linked list around a value x, such that
 * all nodes of value less than x come before all nodes greater than or
 * equal to x.  If x is contained within the list, the values of x only
 * need to be after the elements less than x.  The partition element can
 * appear anywhere in the 'right partition'; it does not need to appear
 * between the left and right partitions.
 * example:
 * input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1
 * output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
 */
list<int> partition(const list<int>& input, int partition_value)
{
	list<int> partitioned_list;

	list<int>::const_iterator iter = input.begin();
	while (iter != input.end())
	{
		if ((*iter) >= partition_value)
		{
			partitioned_list.push_back(*iter);
		}
		else
		{
			partitioned_list.push_front(*iter);
		}
		iter++;
	}
	return partitioned_list;
}

int test_partition()
{
	list<int> test_list;
	for (int i = 100; i > 1; i--)
	{
		test_list.push_back(i);
	}

	list<int> retval = partition(test_list, 36);

	list<int>::const_iterator iter = retval.begin();
	while (iter != retval.end())
	{
		cout << *iter << " ";
		iter++;
	}

	return 0;
}

