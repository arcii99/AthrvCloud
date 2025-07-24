//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to implement bucket sort
void bucketSort(int arr[], int n) {
    // Create n empty buckets
    int i, j;
    int *count = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }
    // Increment the count of the corresponding bucket based on input values
    for (i = 0; i < n; i++) {
        ++count[arr[i]];
    }
    // Sort the elements in each bucket
    for (i = 0, j = 0; i < n; i++) {
        for (; count[i] > 0; count[i]--) {
            arr[j++] = i;
        }
    }
    // Free the count array
    free(count);
}

// Driver code
int main() {
    int arr[] = { 42, 21, 5, 91, 72, 86, 15, 28, 73, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    printArray(arr, n);

    // Sort the array
    bucketSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}