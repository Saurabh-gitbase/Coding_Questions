/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1
*/

using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    int max=INT_MIN;
	    int curr=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        curr += arr[i];
	        
	        if(curr>max)
	        {
	            max = curr;
	        }
	        
	        if(curr<0)
	        {
	            curr = 0;
	        }
	        
	   }
	   cout<< max<<endl;
	    
	}
	
	return 0;
}
