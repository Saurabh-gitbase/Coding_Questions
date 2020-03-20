/*Allocate minimum number of pages
Given number of pages in n different books and m students.

Input : pages[] = {12, 34, 67, 90}
        m = 2
Output : 113
Approach - 
we take a mid value between min 0 and max total sum of pages and assume it as solution.
check it if it is true or not.
their will be two cases 
[1] students are exceding means we have to increase the number of pages one student can read at a time (start = mid+1)
[2] students are satisfying the condition but we try find any other val smaller to current that can satisfy this condition (end = mid-1) for finding optimal solution.
*/
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[],int n,int m,int curr_min)
{
	int curr_sum = 0;
	int student = 1;

	for(int i=0;i<n;i++)
	{
		if(curr_sum > curr_min)
		{
			return false;
		}

		if(curr_sum + arr[i] > curr_min)
		{
			student += 1;
			curr_sum = arr[i];

			if(student > m)
			{
				return false;
			}
		}
		else
		{
			curr_sum += arr[i];
		}
	}
	return true;
}

int findPages(int arr[],int n,int m)
{
	if(m>n)
	{
		return -1;
	}
	long long int sum = 0;

	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}

	int start = 0, end = sum;
	int result = INT_MAX;

	while(start<=end)
	{
		int mid = (start+end)/2;

		if(isPossible(arr,n,m,mid))
		{
			result = min(result,mid);
			end = mid-1;
		}
		else
		{
			start = mid+1;
		}
	}
	return result;
}

int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,m; cin>>n>>m;

		int arr[n];

		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		cout<<findPages(arr,n,m);
	}
}
