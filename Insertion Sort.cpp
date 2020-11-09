#include <iostream>

using namespace std;

int * insertionSort(int arr[],int n){
    // Loop from 2nd element to n
    for(int i=1;i<n;i++){
        // Save current element
        int current = arr[i];
        int k = i-1;
        // Loop in reverse order and if element > current save it at k+1 index
        while(k>=0 && arr[k]>current){
           arr[k+1] = arr[k];
           k--;
        }
        arr[k+1] = current;
    }
    return arr;
}


int main()
{
    int arr[] = {8,7,1,2,5,1,2,3,4,1,12,2,3};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int *result = insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<*(result+i)<<" ";
    }
    

    return 0;
}
