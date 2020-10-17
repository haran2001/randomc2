//selection sort
#include<stdio.h>
#include<stdlib.h>

//swap the given elements
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}


//selectionSort function
void selectionSort(int *a, int size){
    int i,j, temp;
    for(i=0; i<size; i++){
        int temp_index = i;
        for(j=i+1; j<size; j++){
            if(a[temp_index] > a[j]){
                temp_index = j;
            }
        }
        swap(&a[temp_index], &a[i]);
    }
}


int main(){
    //initialize the array
    int arr[] = {30,2,4,1};
    //size of the array
    int size = 4;
    
    //calling the selectionSort function
    selectionSort(arr, size);
    
    //print the sorted array
    for(int i=0;i<size; i++){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}