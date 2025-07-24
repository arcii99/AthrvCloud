//FormAI DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>

// function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to implement bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place    
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// main function to test the sorting algorithm
int main() {
    int arr[] = {25, 45, 2, 1, 16, 38};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original Array: ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted Array: ");
    printArray(arr, n);
    return 0;
}