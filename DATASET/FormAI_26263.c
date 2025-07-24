//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Custom function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Bucket sort implementation
void bucketSort(int arr[], int n) {
    int max = getMax(arr, n);
    int bucketSize = max / 10 + 1; // Set bucket size as per range
    int **buckets = (int **)malloc(bucketSize * sizeof(int *)); // Allocate memory for the buckets

    // Initialize buckets values to zero
    for (int i = 0; i < bucketSize; i++) {
        buckets[i] = (int *)calloc(n, sizeof(int));
    }
    
    // Insert elements into respective buckets based on range
    for (int i = 0; i < n; i++) {
        int bucketIdx = arr[i] / 10;
        buckets[bucketIdx][i] = arr[i];
    }

    // Sort elements within each bucket using insertion sort
    for (int i = 0; i < bucketSize; i++) {
        int *bucket = buckets[i];
        for (int j = 1; j < n; j++) {
            int current = bucket[j];
            int k = j - 1;
            while (k >= 0 && bucket[k] > current) {
                bucket[k + 1] = bucket[k];
                k--;
            }
            bucket[k + 1] = current;
        }
    }
    
    // Merge elements from each bucket into the original array
    int idx = 0;
    for (int i = 0; i < bucketSize; i++) {
        int *bucket = buckets[i];
        for (int j = 0; j < n; j++) {
            if (bucket[j] != 0) {
                arr[idx++] = bucket[j];
            }
        }
    }

    // Free memory allocated for the buckets
    for (int i = 0; i < bucketSize; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    // Test case
    int arr[] = { 27, 38, 12, 39, 27, 16, 24, 5, 11, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}