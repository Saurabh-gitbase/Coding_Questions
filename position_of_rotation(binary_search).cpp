/*
Find the position of rotation in an sorted array.
0 1 2 3 4 5 6 
5 6 7 8 1 2 3 
end 3
start 5
mid 8

if(mid>end)
	start = mid+1
else if(mid<end)
	end = mid-1

*/

#include<bits/stdc++.h>
using namespace std;

void solution(int arr[],int n)
{
	int start = 0,end=n-1;
	int mid = start + (end-start)/2;

	while(start<=end)
	{
		if(arr[mid]<arr[end])
		{
			end = mid-1;
		}
		else if(arr[mid]>arr[end])
		{
			start = mid+1;
		}
		else
			break;
		 mid = start + (end-start)/2;
	}

	cout<<mid;	
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];

		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		solution(arr,n);
	}
}