/*
Given an array of distinct +ve integers. The task is to count all the triplets such that sum of two elements equals the third element.
INPUT - [1 2 3 4 5 6]
OUTPUT - 6
*/

#include<bits/stdc++.h>
using namespace std;

int countTriplets(int arr[],int n)
{
  if (n==0)
  {
    return -1;
  }
  
  int count = 0;
  for(int i=n-1;i>=2;i++)
  {
    int j=0;
    int k=i-1;
    
    while(j<k)
    {
      if(arr[i]+arr[j] == arr[k])
      {
        count += 1;
        j++;
        k--;
      }
      else if(arr[i]+arr[j] < arr[k])
      {
        j++;
      }
      else
      {
        k--;
      }
    }
  }
  if(count == 0)
    return -1;
  
  return count;
}

int main()
{
  int n; cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  cout<<countTriplets(arr,n)<<endl;
}

