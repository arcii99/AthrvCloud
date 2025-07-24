//FormAI DATASET v1.0 Category: Sorting ; Style: standalone
#include <stdio.h>

// Function to swap two elements
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to print the array
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Bubble sort function
void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        // Last i elements are already sorted
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Given array: \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("\nSorted array: \n");
    printArray(arr, n);
    return 0;
}