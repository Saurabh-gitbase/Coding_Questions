
// O(n) O(n)
int trappingRain(int arr[],int n){
  int rightMax[n];
  int leftMax[n];
  
  leftMax[0] = arr[0];
  for(int i=1;i<n;i++){
    leftMax[i] = max(leftMax[i-1],arr[i]);
  }
  
  rightMax[n-1] = arr[n-1];
  for(int i=n-2;i>=0;i--){
    rightMax[i] = max(rightMax[i+1],arr[i]);
  }
  
  int result = 0;
  
  for(int i=0;i<n;i++)
    result+= min(leftMax[i],rightMax[i])-arr[i];
    
  return result;
}



// O(n) O(1)
int trappingRain(int arr[],int n){
  int result = 0;
  
  int leftMax = 0;
  int rightMax = 0;
  
  int leftIndex = 0;
  int rightIndex = n-1;
  
  while(leftIndex <= rightIndex){
    if(arr[leftIndex]<arr[rightIndex]){
      if(arr[leftIndex] > leftMax)
        leftMax = arr[leftIndex];
      else
        result += (leftMax - arr[leftIndex]);
      leftIndex++;
    }
    else{
      if(arr[rightIndex] > rightMax){
        rightMax = arr[rightIndex];
      }
      else
        result += (rightMax-arr[rightIndex]);
      rightIndex--;
    }  
  }
  
  return result;
}

int main(){

}
