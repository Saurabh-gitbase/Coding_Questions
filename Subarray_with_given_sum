#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);     // fast io in c++
  cin.tie(NULL);
	
  int t; //no of test cases
	cin>>t;
	while(t--)
	{
	    int n,sum;	cin>>n>>sum;   // size and sum
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	    	cin>>arr[i];
	    }

	    int curr_sum = 0;         // current sum of the sub array
	    int start = 0;
	    bool flag = false;        // flag to know if we found a solution or not.

	    for(int i=0;i<n;i++)
	    {
	    	curr_sum += arr[i];     // adding elements to current sum.

	    	if(curr_sum>sum)        // if current sum becomes greater than sum delete elements from start till it becomes equal or less.
	    	{
	    		while(curr_sum>sum)
	    		{
	    			curr_sum-=arr[start];
	    			start+=1;
	    		}
	    	}
	    	if(curr_sum==sum)       // if it becoms equal solution found, flag will set true loop will end.
	    	{
	    		cout<<start+1<<" "<<i+1<<"\n";
	    		flag = true;
	    		break;
	    	}
	    }
	    if(flag == false)       // no solution found print -1.
	    {
	    	cout<<-1<<"\n";
	    }

	}
	
	return 0;
}
