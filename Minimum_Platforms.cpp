/*Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of platforms required for the railway station so that no train waits.*/

#include<bits/stdc++.h>
using namespace std;

int minPlatform(int a[],int d[],int n)
{
  multimap<int,char> data;
  for(int i=0;i<n;i++)
  {
    data.make_pair(a[i],'a');
  }
  for(int i=0;i<n;i++)
  {
    data.make_pair(d[i],'d');
  }
  
  int curr_count = 0;
  int max_count = 0;
  
  multimap<int,char> :: iterator it = data.begin();
  
  for(;it!=data.end();it++)
  {
    if(it->second == 'a')
      curr_count++;
    else
      curr_count--;
    
    if(curr_count>max_count)
      max_count = curr_count;
  }
  
  return max_count;
}
  

int main()
{
}
