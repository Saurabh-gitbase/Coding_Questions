#include <iostream>

using namespace std;

int * bubbleSort(int arr[],int n){
    bool isSorted;
    for(int i=0;i<n;i++){
        isSorted = true;
        for(int j=1;j<n-i;j++){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                isSorted=false;
            }
        }
        if(isSorted)
            return arr;
    }
    return arr;
}


int main()
{
    int arr[] = {8,7,1,2,5,1,2,3,4,1,12,2,3};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int *result = bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<*(result+i)<<" ";
    }
    

    return 0;
}
