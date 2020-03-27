#include<bits/stdc++.h>
using namespace std;

int nextgap(int gap)
{
    if(gap<=1)
    {
        return 0;
    }
    return (gap/2) + (gap%2); 
}

void merge(int *arr1,int *arr2,int n,int m)
{
    int i,j,gap=n+m;
    
    for(gap=nextgap(gap);gap>0;gap=nextgap(gap))
    {
        for(i=0;i+gap<n;i++)
        {
            if(arr1[i]>arr1[i+gap])
            {
                swap(arr1[i],arr1[i+gap]);
            }
        }
        
        for(j= gap>n ? gap-n:0; i<n && j<m ;i++,j++)
        {
            if(arr1[i]>arr2[j])
            {
                swap(arr1[i],arr2[j]);
            }
        }
        
        if(j<m)
        {
            for(j=0;j+gap<m;j++)
            {
                if(arr2[j]>arr2[j+gap])
                {
                    swap(arr2[j],arr2[j+gap]);
                }
            }
        }
    }
}


int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n;
	    cin>>m;
	    int arr1[n],arr2[m];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr1[i];
	    }
	    for(int i=0;i<m;i++)
	    {
	        cin>>arr2[i];
	    }
	    
	    
	    merge(arr1,arr2,n,m);
	    
	    for(int i=0;i<n;i++)
	    {
	        cout<<arr1[i]<<" ";
	    }
	    for(int i=0;i<m;i++)
	    {
	        cout<<arr2[i]<<" ";
	    }
	    cout<<endl;
	    
	    
	}
	
	return 0;
}