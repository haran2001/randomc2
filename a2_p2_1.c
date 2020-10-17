//quick sort
#include<stdio.h>
#include<stdlib.h>

//swap two numbers
void swap(int*a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

//find the partition index using the right most element
int partition(int *a, int left, int right){
    int j;
    int i = left -1;
    for(j=left; j<right; j++){
        if(a[j]<a[right]){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[right]);
    return (i+1);
}

//quicksort function
void quickSort(int*arr, int left, int right){
    if(left < right){
        int pi;
        int m = left + (right-left)/2;

        pi = partition(arr, left, right);
        quickSort(arr, left, pi-1);
        quickSort(arr, pi+1, right);
    }
}



int main(){
    //initialize the array
    int arr[] = {3,2,4,1};
    //size of the array
    int size = 4;
    
    //calling the quickSort function
    quickSort(arr, 0, size-1);
    
    //print the sorted array
    for(int i=0;i<4; i++){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}