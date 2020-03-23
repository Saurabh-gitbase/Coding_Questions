/*
Given an array that contains both positive and negative integers, find the product of the maximum product subarray.  
*/

#include<bits/stdc++.h>
using namespace std;

int maxPro(int arr[],int n)
{
  int ans = INT_MIN;
  int currmax = 1;
  int currmin = 1;
  int premax;
  
  for(int i=0;i<n;i++)
  {
    if(arr[i] > 0)                          // Curr is +ve mul by currmax and mix to store max and min value till this point.
    {
      currmax *= arr[i];
      currmin = min(1,currmin*arr[i]);
    }
    
    else if(arr[i] == 0)                    // 0 incountered means we have to start again.
    {
      currmax = 0;
      currmin = 1;
    }
    
    else if(arr[i] < 0)                     // -ve value means maxvalue will become min and min will become max.
    {
      premax = currmax;
      currmax = currmin*arr[i];
      currmin = premax*arr[i];
    }
    
    ans = max(ans,currmax);                
    
    if(currmax <= 0)
      currmax = 1;
  }
  return ans;
}
int main()
{
  int n; cin>>n;
  int arr[n];
  
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  
  cout<<maxPro(arr,n);
}
