/*
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer mod 10^9 + 7.
*/
#include<bits/stdc++.h>
using namespace std;
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
	    
	    long int a[n],b[n];
	    a[0]=1;
	    b[0]=1;
	    
	    for(int i=1;i<n;i++)
	    {
	        a[i] = (a[i-1]+b[i-1])%1000000007;
	        b[i] = a[i-1];
	    }
	    cout<<(a[n-1]+b[n-1])%1000000007<<"\n";
	}
	
	return 0;
}
