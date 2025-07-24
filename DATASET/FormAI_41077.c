//FormAI DATASET v1.0 Category: Sorting ; Style: thoughtful
#include <stdio.h>

/* Function to swap the positions of two items in an array */
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/* Function to perform a bubble sort on an array */
void bubble_sort(int arr[], int n) {
    /* Variable to check if any swaps were made during a pass */
    int swapped = 0;

    /* Perform passes until no swaps are made */
    do {
        swapped = 0;
        /* Perform a pass */
        for (int i = 0; i < n-1; i++) {
            /* If the adjacent elements are in the wrong order, swap them */
            if (arr[i] > arr[i+1]) {
                swap(arr, i, i+1);
                swapped = 1;
            }
        }
    } while (swapped);
}

int main() {
    /* Declare and initialize an array */
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    /* Print the unsorted array */
    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    /* Sort the array */
    bubble_sort(arr, n);

    /* Print the sorted array */
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}