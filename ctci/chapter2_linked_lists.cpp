/*
 * test.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: Yascha
 */

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
#include <iterator>

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





/*
 * 2.5 Sum Lists
 * You have two numbers represented by a linked list, where each node
 * contains a single digit.  The digits are stored in reveres order,
 * such that the 1s digit is at the head of the list.  Write a function
 * that adds the two numbers and returns the sum as a linked list.
 * ie.
 * Input: (7 -> 1 -> 6) + (5 -> 9 -> 2)  -- which is 617 + 295
 * Output: 2 -> 1 -> 9 -- which is 912
 */

void sum_lists_recursive(list<int>& ret, list<int>::const_iterator i1,
		list<int>::const_iterator i1_end, list<int>::const_iterator i2,
		list<int>::const_iterator i2_end, bool carry);


list<int> sum_lists(list<int>& l1, list<int>& l2)
{
	list<int> ret;
	list<int>::const_iterator main_it, main_end;
	list<int>::const_iterator secondary_it, secondary_end;
	if (l1.size() >= l2.size())
	{
		main_it = l1.begin();
		main_end = l1.end();
		secondary_it = l2.begin();
		secondary_end = l2.end();
	}
	else
	{
		main_it = l2.begin();
		main_end = l2.end();
		secondary_it = l1.begin();
		secondary_end = l1.end();
	}

	sum_lists_recursive(ret, main_it, main_end,
			secondary_it, secondary_end, false);


	return ret;
}


void sum_lists_recursive(list<int>& ret, list<int>::const_iterator i1,
		list<int>::const_iterator i1_end, list<int>::const_iterator i2,
		list<int>::const_iterator i2_end, bool carry)
{
	int my_digit = 0;
	bool carry_forward = false;
	if (i1 != i1_end)
	{
		my_digit += *i1;
		i1++;
	}
	if (i2 != i2_end)
	{
		my_digit += *i2;
		i2++;
	}
	if (carry)
	{
		my_digit++;
	}

	if (my_digit > 10)
	{
		carry_forward = true;
		my_digit = my_digit % 10;
	}

	if (i1 == i1_end && i2 == i2_end && !carry)
	{
		return;
	}

	ret.push_back(my_digit);
	sum_lists_recursive(ret, i1, i1_end, i2, i2_end, carry_forward);
}


int test_sum_lists()
{

	list<int> test_list_one;
	test_list_one.push_back(7);
	test_list_one.push_back(1);
	test_list_one.push_back(6);

	cout << "test list one:\t";
	copy(test_list_one.begin(), test_list_one.end(), ostream_iterator<int>(cout, " "));

	list<int> test_list_two;
	test_list_two.push_back(5);
	test_list_two.push_back(9);
	test_list_two.push_back(2);

	cout << "\ntest list two:\t";
	copy(test_list_two.begin(), test_list_two.end(), ostream_iterator<int>(cout, " "));

	list<int> result = sum_lists(test_list_one, test_list_two);

	cout << "\n result:\t";

	copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
	return 0;
}



/* 2.6 Palindrome
 * Implement a function to check if a linked list is a palindrome.
 */
bool is_palindrome(list<int>& l)
{
	list<int>::const_iterator forward = l.begin();
	list<int>::const_reverse_iterator backward = l.rbegin();
	while (forward != l.end())
	{
		if (*forward != *backward)
		{
			return false;
		}
		forward++;
		backward++;
	}
	return true;
}


int test_is_palindrome()
{
	list<int> test_list_not_palindrome, test_list_palindrome;
	for (int i = 0; i < 16; i++)
	{
		test_list_not_palindrome.push_back(i);
	}

	test_list_palindrome = test_list_not_palindrome;
	copy(test_list_not_palindrome.rbegin(), test_list_not_palindrome.rend(),
			back_inserter(test_list_palindrome));

	cout << "non-palindrome list:\n";
	copy(test_list_not_palindrome.begin(), test_list_not_palindrome.end(),
			ostream_iterator<int>(cout, " "));

	if (!is_palindrome(test_list_not_palindrome))
	{
		cout << "\nnon-palindrome confirmed non-palindrome!\n";
	}

	cout << "palindrome list:\n";
	copy(test_list_palindrome.begin(), test_list_palindrome.end(),
			ostream_iterator<int>(cout, " "));

	if (is_palindrome(test_list_palindrome))
	{
		cout << "\npalindrome confirmed palindrome!\n";
	}

	return 0;
}

