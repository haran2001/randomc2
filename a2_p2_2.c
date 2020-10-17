//quick sort
#include<stdio.h>
#include<stdlib.h>

void merge(int *a, int left, it right){

}

void mergeSort(int *a, int left, int right){
    int m = left + (right-left)/2;
    
}

int main(){
    //initialize the array
    int arr[] = {3,2,4,1};
    //size of the array
    int size = 4;
    
    //calling the mergeSort function
    quickSort(arr, 0, size-1);
    
    //print the sorted array
    for(int i=0;i<4; i++){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}