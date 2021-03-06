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

	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());

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



/* 1.4 Palindrome Permutation
 * Given a string, write a function to check if it is a permutation of a
 * palindrome.  A palindrome is a word or phrase that is the same forwards
 * and backwards.  A premutation is a rearrangement of letters.  The
 * palindrome does not need to be limited to just dictionary words.
 * ie. Input:  Tact Coa
 * Output: True ("taco cat", "atco cta", etc.)
 */

/* Approach:
 * The problem doesn't ask us to compute the palindromes, just to confirm
 * if the input string can be made into palindromes.  We know that all
 * palindromes have an even number of each character (except 1 in the middle).
 * As such, we can inspect the characters of the input string to determine
 * if it meets the criteria (<= 1 char with an odd number of instances).
 */

bool palindrome_permutation(string str)
{
	std::map<char, int> str_map;
	string::const_iterator str_iter = str.begin();
	string::const_iterator str_iter_end = str.end();

	// count the instances of each character and store them in str_map
	while (str_iter != str_iter_end)
	{
		str_map[*str_iter] += 1;
		str_iter++;
	}

	// if we find more than 1 character with an odd number
	// of instances, return false
	map<char, int>::const_iterator map_iter = str_map.begin();
	map<char, int>::const_iterator map_iter_end = str_map.end();
	int num_odd_instances;
	while (map_iter != map_iter_end)
	{
		if (map_iter->second % 2 != 0)
		{
			num_odd_instances++;
			if (num_odd_instances > 1)
			{
				break;
			}
		}
		map_iter++;
	}

	if (num_odd_instances > 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}


int test_palindrome_permutation()
{
	string test = "TacTcoa";
	if (palindrome_permutation(test))
	{
		cout << "String \"" << test << "\" is a palindrome permutation."
				<< endl;
	}
	else
	{
		cout << "String \"" << test << "\" is not a palindrome :(" << endl;
	}
	return 0;
}


/*
 * 1.5 One Away
 * There are three types of operations that can be performed on
 * a given string: insert a character, remove a character, or
 * replace a character.
 * Given 2 strings, write a function to determine if they are
 * 1 edit away.
 */

/*
 * Approach:
 * We can iterate over both strings comparing the characters.
 * As soon as we encounter a mis-match character, we can branch
 * off into 3 analyses: add a character, remove a character, and
 * replace a character.  If none of these approaches succeed, then
 * we are not 1 edit away.
 */


typedef string::const_iterator iter;
bool compareToFailure(iter s1, iter s1_end, iter s2, iter s2_end)
{
	while (s1 != s1_end && s2 != s2_end && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (s1 == s1_end && s2 == s2_end)
	{
		return true;
	}
	return false;
}


bool one_away(string s1, string s2)
{
	string::iterator i1 = s1.begin();
	string::iterator i2 = s2.begin();

	while (i1 != s1.end() && i2 != s2.end() && *i1 == *i2)
	{
		i1++;
		i2++;
	}
	if (i1 == s1.end() && i2 == s2.end())
	{
		return true;
	}
	else
	{
		string::size_type s1_size = s1.size();
		string::size_type s2_size = s2.size();

		if (s1_size == s2_size)
		{
			// try replace string 1 char
			char old_i1 = *i1;
			*i1 = *i2;
			if (compareToFailure(i1, s1.end(), i2, s2.end()))
			{
				cout << "Replacing a char from string 1 worked.\n";
				return true;
			}

			*i1 = old_i1;

			// try replace string 2 char
			*i2 = *i1;
			if (compareToFailure(i1, s1.end(), i2, s2.end()))
			{
				cout << "Replacing a char from string 2 worked.\n";
				return true;
			}
		}
		else if ((s1_size + 1) == s2_size)
		{
			// try add string 1 char
			i1 = s1.insert(i1, *i2);
			if (compareToFailure(i1, s1.end(), i2, s2.end()))
			{
				cout << "Adding a char to string 1 worked.\n";
				return true;
			}
			s2.erase(i2);

			// try remove string 2 char


		}
		else if (s1_size == (s2_size + 1))
		{
			// try add string 2 char
			i2 = s2.insert(i2, *i1);
			if (compareToFailure(i1, s1.end(), i2, s2.end()))
			{
				cout << "Adding a char to string 2 worked.\n";
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}



int test_one_away()
{
	string s1 = "abc";
	string s2 = "abxc";

	cout << s1 + " and " + s2 << endl;
	if (one_away(s1, s2))
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}

	return 0;
}
