//insertion sort
#include<stdio.h>
#include<stdlib.h>

//insertionSort function
void insertionSort(int *a, int size){
  int i, j, temp;
  for(i=0; i<size; i++){
      temp = a[i];
      j = i-1;
        while(j>=0 && temp>a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
  }
}


int main(){
    //initialize the array
    int arr[] = {30,20,45,1};
    //size of the array
    int size = 4;
    
    //calling the insertionSort function
    insertionSort(arr, size);
    
    //print the sorted array
    for(int i=0;i<size; i++){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}