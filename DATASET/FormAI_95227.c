//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: genious
#include <stdio.h>
#include <stdlib.h>

/* Genious-style performance-critical component example */
int main() {
    int n = 1000000;

    // Allocate memory for array of integers
    int *arr = (int *) malloc(n * sizeof(int));

    // Populating the array with random integers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    // Sorting the array using QuickSort algorithm
    quicksort(arr, 0, n-1);

    // Printing the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Freeing the allocated memory
    free(arr);

    return 0;
}

/* QuickSort algorithm */
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning
        int pivot = partition(arr, low, high);

        // Sorting left and right sub-arrays
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }
}

/* Partitioning function */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

/* Swapping function */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}