//bubble sort
#include<stdio.h>
#include<stdlib.h>

//swap the given elements
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}


//bubbleSort function
void bubbleSort(int *a, int size){
    int i,j;
    for(i=0; i<size; i++){
        for(j=i; j<size; j++){
            if(a[j]<a[i])
                swap(&a[i], &a[j]);
        }
    }
}


int main(){
    //initialize the array
    int arr[] = {3,2,4,1};
    //size of the array
    int size = 4;
    
    //calling the bubbleSort function
    bubbleSort(arr, size);
    
    //print the sorted array
    for(int i=0;i<size; i++){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}