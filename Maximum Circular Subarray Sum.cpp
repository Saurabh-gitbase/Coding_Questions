int circularSubarraySum(int arr[], int n){
    
    // your code here
    int totalSum = 0;
    int maxSum = INT_MIN;
    int maxrevSum = INT_MIN;
    int currSum = 0;
    int currrevSum =0;
    
    if(n==1)
        return arr[0];
    
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
        currSum+=arr[i];
        currrevSum+=(-arr[i]);
        if(currSum>maxSum)
            maxSum = currSum;
        if(currSum<0)
            currSum = 0;
        
        if(currrevSum>maxrevSum)
            maxrevSum = currrevSum;
        if(currrevSum<0)
            currrevSum = 0;
        
    }
    if((totalSum+maxrevSum)==0 && maxSum<0)
        return maxSum;
    return((totalSum+maxrevSum)>maxSum?(totalSum+maxrevSum):(maxSum));
}


int maxSum(int arr[], int n){
  int totalSum = arr[0];
  
  int maxSum = arr[0];
  int minSum = arr[0];
  
  int currMax = arr[0];
  int currMin = arr[0];
  
  for(int i=1;i<n;i++){
    totalSum+=arr[i];
    
    currMax = max(currMax+arr[i],arr[i]);
    maxSum = max(currMax, maxSum);
    
    currMin = min(currMin+arr[i],arr[i]);
    minSum = min(currMin, minSum);
  }
  
  if(totalSum == minSum)
     return maxSum;
  return max(maxSum, totalSum-minSum);
}

int main(){
}
