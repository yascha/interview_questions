//Kadane's Algorithm
//Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

// Yascha's difficulty mode:: do it using only a list with iterators and no direct access to the array

#include <iostream>
#include <list>
using namespace std;


typedef struct {
  int startingIndex;
  int endingIndex;
  int sum;
} subArray;



void findSubArray (list<int> myList)
{
  int len = myList.size();
  
  subArray currentBiggestSubArray;
  currentBiggestSubArray.startingIndex = 0;
  currentBiggestSubArray.endingIndex = 0;
  currentBiggestSubArray.sum = 0;
  
  typedef list<int>::const_iterator iter;
  iter it = myList.begin();
  
  // Iterate through each item in the array (starting index is i)
  for (int i = 0; i < len; i++)
  {
    // iterate for each length in the array (j is the length of our subarray)
    for (int j = 1; j <= len - i; j++)
    {
      int currentSum = 0;
      iter i2 = it;
      
      // now we have a starting index and a target index, calculate the subarray, k is the current len (from i)
      for (int k = 0; k < j; k++)
      {
        currentSum += *i2;
        if (currentSum > currentBiggestSubArray.sum)
        {
          currentBiggestSubArray.startingIndex = i;
          currentBiggestSubArray.endingIndex = i + k;
          currentBiggestSubArray.sum = currentSum;
        }
        i2++;
      }
    }
    
    // increment our iterator to the next starting spot in the array
    it++;
  }
  
  cout << "Using only a singly linked list:" << endl;
  cout << "Biggest sum found is: " << currentBiggestSubArray.sum << endl;
  cout << "[" << currentBiggestSubArray.startingIndex << ", " << currentBiggestSubArray.endingIndex << "]" << endl;
}




void findSubArray(int myList[], int size)
{
  
  subArray currentBiggestSubArray;
  currentBiggestSubArray.startingIndex = 0;
  currentBiggestSubArray.endingIndex = 0;
  currentBiggestSubArray.sum = 0;
  
  for (int i = 0; i < size; i++)
  {
    for (int j = 1; j + i <= size; j++)
    {
      int currentSum = 0;
      for (int k = 0; k < j; k++)
      {
        currentSum += myList[i+k];
        if (currentSum > currentBiggestSubArray.sum)
        {
          currentBiggestSubArray.startingIndex = i;
          currentBiggestSubArray.endingIndex = i+k;
          currentBiggestSubArray.sum = currentSum;
        }
      }
    }
  }
  cout << "Using direct access:" << endl;
  cout << "Biggest sum found is: " << currentBiggestSubArray.sum << endl;
  cout << "[" << currentBiggestSubArray.startingIndex << ", " << currentBiggestSubArray.endingIndex << "]" << endl;
}

int main()
{
  list<int> myList = { 15, -21, 2, 4, -1, -2, 35, -5, 12, -1, -5, -5, -5, -5, 5, -3, 66, 5, -5, 0001,-25, 25, -7 };
  
  size_t arrayListSize = myList.size();
  int arrayList[arrayListSize];
  int index = 0;
  for (const int &i : myList)
  {
    arrayList[index] = i;
    index++;
  }
  
  findSubArray(myList);
  cout << endl;
  findSubArray(arrayList, arrayListSize);
}
