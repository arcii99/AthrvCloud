//FormAI DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to perform Selection Sort recursively
void selectionSort(int arr[], int n) {

    // Base case: one element left
    if(n == 1) {
        return;
    }

    // Find the maximum element and swap it with the last element
    int i, maxIndex = 0;
    for(i = 1; i < n; i++) {
        if(arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    int temp = arr[n-1];
    arr[n-1] = arr[maxIndex];
    arr[maxIndex] = temp;

    // Recursively sort the remaining elements
    selectionSort(arr, n-1);
}

int main() {

    // Declare an array of integers to be sorted
    int arr[] = {45, 78, 10, 5, 90, 23, 56};

    // Determine the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    printf("Unsorted array: ");
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using Selection Sort
    selectionSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Exit program successfully
    return 0;
}