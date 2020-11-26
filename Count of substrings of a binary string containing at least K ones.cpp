#include <bits/stdc++.h> 
using namespace std; 


int countOfSubstringWithKOnes(string s, int K) 
{ 
	int N = s.length();
	
	if(K>N)
	    return 0;
	
	int res = 0; 
	
	//currCountOfOne stores the current number of 1 in the string
	int currCountOfOne = 0;
	//countOfOne is used to check repeataions in the count of 1 e.g if count of 1 remains same for next 3 iterations this will help us
	int countOfOne = 0;
	
	// stores the frequency of 1
	unordered_map<int,int> freq;
	//stores the value of subarrays possible for that count of 1's
    unordered_map<int,int> result;
	
	freq[0] = 1; 

	
	for (int i = 0; i < N; i++) { 

		currCountOfOne += (s[i] - '0'); 

		if (currCountOfOne >= K) { 
          	
          	int temp_k = K;
          	
          	// check's if we have calculated the possible subarrays ones for the count of 1's then we don't need to find it again instead we can use the previous calculated value
          	if(countOfOne == currCountOfOne){
          	    // res will be updated based on previous result for this freq of 1's
          	    res += result[currCountOfOne];
          	}
          	else{
          	    
          	    int currResult = 0;
          	    // for unique freq we will find the possible subsets
          	    while(temp_k<=currCountOfOne){
				    currResult += freq[currCountOfOne - temp_k];
              	    temp_k++;
                }
                // the result will be stored in the result map for future reference. If we encounter same freq of 1's we can use this result instead of solveing it again
                result[currCountOfOne] = currResult;
                res += currResult;
                
                //countOfOne will update whenever new freq of 1's is found and this will help us to skip solveing subsets for this freq in future iterations
                countOfOne = currCountOfOne;
          	}
		}
		freq[currCountOfOne]++; 
	}
	return res; 
} 


int main() 
{ 
	string s = "10010"; 
	int K = 1; 
	cout << countOfSubstringWithKOnes(s, K) << endl; 
	return 0; 
}

