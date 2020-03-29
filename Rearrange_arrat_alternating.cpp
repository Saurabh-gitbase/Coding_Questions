/*
Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on in O(1) space.
*/

#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[] ,int n)
{
  if(n==1)
  {
    cout<<arr[0]<<endl;
    return;
  }
  if(n==2)
  {
    cout<<arr[1]<<" "<<arr[0]<<endl;
    return; 
  }
  int maxElement = arr[n-1] +1 ;
  int currMin = 0;
  int currMax = n-1;
  
  for(int i=0;i<n;i++)
  {
    if(i%2==0)
    {
      arr[i] += (arr[currMax] % maxElement) * maxElement;
      currMax -- ;
    }
    else
    {
      arr[i] += (arr[currMin] % maxElement) * maxElement;
      currMin++;
    }
  }
  
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]/maxElement<<" ";
  }
  
  cout<<endl;
}


int main()
{
}
