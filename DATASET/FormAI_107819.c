//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float *arr, int n) {
    // Create an array of empty buckets
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;

    // Increment the count of each element in arr
    for (i = 0; i < n; i++)
        count[(int)arr[i]]++;

    // Sort the elements of each bucket
    for (i = 0, j = 0; i < n; i++) {
        while (count[i] > 0) {
            arr[j++] = i;
            count[i]--;
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.67, 0.11, 0.88, 0.25, 0.19, 0.76};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    // Print the original array
    printf("Original array:\n");
    for (i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    // Sort the array
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}