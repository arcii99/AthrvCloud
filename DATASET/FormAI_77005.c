//FormAI DATASET v1.0 Category: Sorting ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Function to swap two values
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        // Last i elements are already sorted, so no need to compare them
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                // Swap the values if arr[j] is greater than arr[j+1]
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Main function
int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}