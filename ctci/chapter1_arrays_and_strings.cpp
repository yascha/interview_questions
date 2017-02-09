#include <iostream>
#include <string>
#include <map>
#include <algorithm>

// Chapter 1

using namespace std;

/* 1.1 Is Unique
 * Implement an algorithm to detect if a string has all unique
 * characters.
 * What if you cannot use additional data structures?
 */

using std::string;
using std::map;

/* Approach:
 * the level 0 approach is to iterate over each character in
 * the string and check if there is another copy of it.
 * This is a O(n^2) approach (technically N(N-1)/2), which is pretty slow.
 *
 * Let's try iterating through the string a single time and
 * marking each character we see.  If we've already seen that
 * character before, the character is not unique and thus the
 * string does not contain only unique characters.
 *
 */
bool is_unique(const string& str)
{
	map<char, bool> str_map;
	string::size_type index = 0;

	while (index != str.size())
	{
		char current_char = str[index];
		if (str_map[current_char] == true)
		{
			return false;
		}
		else
		{
			str_map[current_char] = true;
			index++;
		}
	}
	return true;

}


int test_is_unique()
{
	string test = "teST";
	if (is_unique(test))
	{
		std::cout << "No Unique characters found" << std::endl;
	}
	else
	{
		std::cout << "Unique characters detected" << std::endl;
	}
	return 0;
}



/* 1.2 Check Permutation
 * Given two strings, write a method to determine if one is a
 * permutation of the other.
 */
/*
 * Approach:
 * Well we know that if the strings are different sizes, they
 * aren't permutations.
 * We can make a copy of each string and sort them and then compare
 * character by character, if they match, they are permutations.
 */

bool check_permutation(string str1, string str2)
{
	if (str1.size() != str2.size())
	{
		return false;
	}

	// note that since we haven't passed a reference to the string,
	// the C++ implementation has made a copy for us.  This isn't
	// super efficient, but since we are manipulating (sorting)
	// the data, it is necessary here.

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	string::size_type index = 0;
	while (index != str1.size())
	{
		if (str1[index] != str2[index])
		{
			return false;
		}
		index++;
	}
	return true;
}

using std::cout;	using std::endl;

int test_check_permutation()
{
	string str1 = "string 1";
	string str2 = "1 gnirts";

	if (check_permutation(str1, str2))
	{
		cout << str1 << " and " << str2 << " are permutations!" << endl;
	}
	else
	{
		cout << str1 << " and " << str2 << " are not permutations :(" << endl;
	}

	return 0;
}



/* 1.3 URLify
 * Write a method to replace all spaces in a string with "%20".
 * You may assume that the string has sufficient space at the end to
 * support all of the additional characters and that you are given
 * the 'true' length of the string.
 *
 */

/* Approach:
 * I'm assuming we aren't allowed to just use the STL to
 * do the replacement.
 *
 * If we iterate forward through the string and insert '%20'
 * whenever we find a space, this would be a worst-case O(n^2)
 * solution.
 * Instead what we can do is start at the end of the string and
 * iterate towards the start, copying the non-space characters to
 * their proper place and adding '%20' where necessary.
 */
string URLify(string str, string::size_type length)
{
	string::size_type read_ptr, write_ptr;

	read_ptr = write_ptr = length - 1;

	//iterate the read pointer past all the trailing spaces
	while (str[read_ptr] == ' ')
	{
		read_ptr--;
	}

	// now we have the read pointer on the last non-space char
	// of our string
	while (write_ptr > 0)
	{
		if (str[read_ptr] != ' ')
		{
			str[write_ptr] = str[read_ptr];
			read_ptr--;
			write_ptr--;
		}
		else
		{
			str[write_ptr - 2] = '%';
			str[write_ptr - 1] = '2';
			str[write_ptr ] = '0';
			read_ptr--;
			write_ptr >= 3 ? write_ptr -= 3 : write_ptr = 0;
		}
	}
	return str;
}


int test_urlify()
{
	string test = "Mr John Smith    ";

	cout << URLify(test, test.size()) << endl;

	return 0;
}



