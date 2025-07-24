//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to swap two elements in an array
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// bubble sort algorithm
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr, n);

    printf("\nSorting in progress...\n");
    bubbleSort(arr, n);

    printf("\nAfter sorting: ");
    printArray(arr, n);

    printf("\nCongratulations, your array is now sorted!\n");

    return 0;
}