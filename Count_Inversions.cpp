/*
Given an array of positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Approch - We used modified merge sort to count inversions.
*/

#include<bits/stdc++.h>
using namespace std;

long int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i=left;
    int j=mid;
    int k=left;
    long int inv_count = 0;
    
    while((i<=mid-1) && (j<=right))
    {
        if(arr[i]<=arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count += (mid-i);
        }
    }
    
    while(i<=mid-1)
    {
        temp[k++] = arr[i++];
    }
    while(j<=right)
    {
        temp[k++] = arr[j++];
    }
    
    for(i=left;i<=right;i++)
    {
        arr[i] = temp[i];
    }
    
    
    return inv_count;
}

long int _mergesort(int arr[],int temp[],int left,int right)
{
    int mid;long int inv_count=0;
    
    if(right>left)
    {
        mid = (right+left) /2;
        
        inv_count += _mergesort(arr,temp,left,mid);
        inv_count += _mergesort(arr,temp,mid+1,right);
        
        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

long int mergesort(int arr[],int n)
{
    int temp[n];
    return _mergesort(arr,temp,0,n-1);
}

int main()
 {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	
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
	    
	    cout<<mergesort(arr,n)<<"\n";
	}
	
	return 0;
}
