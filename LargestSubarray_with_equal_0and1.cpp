/*
Given an array containing only 0s and 1s, find the largest subarray which contain equal no of 0s and 1s. Expected time complexity is O(n).
Approach-
We will make all 0's in the array as -1 because equal number of 1 and -1 will cancel out each other and produce sum as 0. [CASE: Equal number of 0 and 1 from start to that point]
If two sum values are equal that also means that we have equal number of 0's and 1's from occurance of previous sum and new sum [CASE: Equal number of 0 and 1 in between.]

[1] Make all 0's in the array as -1.
[2] Loop through the array and check for sum = 0 (means till this index we have equal number of 0's and 1's.
    [3] If sum is not equal to 0 store it in hash map along with its index so that when that sum occurs again will tell that we have found eual number of zeros and one form previous sum index to current index.
    [4]Whenever we will find a match we will store the max value among the two.
[5] Return the maxval.

*/

#include<bits/stdc++.h>
using namespace std;

int maxLen(int arr[],int n)
{
  unordered_map<int,int> check;
  int sum=0;
  int maxVal = INT_MIN;
  for(int i=0;i<n;i++)
  {
    if(arr[i] == 0)
      arr[i] = -1;
  }
  
  for(int i=0;i<n;i++)
  {
    sum+=arr[i];
    if(sum==0)
      max_val = max(max_val,i+1);
    
    if(check.find(sum)!=check.end())
    {
      max_val = max(max_val,i-check[sum]);
    
    }
    else
      check[sum]=i;
   }
   if(max_val == INT_MIN)
    return 0;
   return max_val;
}

int main()
{
  maxLen(arr,n);
}
