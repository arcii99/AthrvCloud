//FormAI DATASET v1.0 Category: Sorting ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Declare the function for heapify
void heapify (int arr[], int n, int i) {
    int largest = i;    // Initialize largest index as root
    int l = 2*i + 1;    // Left child index
    int r = 2*i + 2;    // Right child index

    // Check if left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Check if right child is larger than root
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        // Swap the elements
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Define heap sort function
void heapSort(int arr[], int n) {
    // Build the max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n-1; i >= 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

// Define main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    heapSort(arr, n);

    printf("Sorted Array: ");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}