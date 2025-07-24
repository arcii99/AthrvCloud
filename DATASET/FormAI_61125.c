//FormAI DATASET v1.0 Category: Sorting ; Style: brave
#include<stdio.h>

// Define the swap function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Define the bubble sort function
void bubbleSort(int arr[], int size){
    int i, j;
    for(i=0; i<size-1; i++){
        for(j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Define the main method
int main(){
    int arr[] = {12, 34, 2, 45, 3, 6, 23, 54};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i;

    printf("Unsorted Array: \n");
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, size);

    printf("Sorted Array: \n");
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}