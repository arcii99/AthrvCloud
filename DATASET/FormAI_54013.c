//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define limits for values and buckets
#define MIN_VALUE 0
#define MAX_VALUE 99
#define NUM_BUCKETS 10

// Helper function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Helper function to swap two values in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bucket Sort implementation function
void bucketSort(int arr[], int n) {
    // Create buckets and output array
    int buckets[NUM_BUCKETS][n];
    int output[n];
    
    // Initialize bucket sizes to 0
    int bucketSizes[NUM_BUCKETS] = {0};
    
    // Place array elements into their respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / MAX_VALUE * (NUM_BUCKETS - 1);
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }
    
    // Sort elements within each non-empty bucket using Bubble Sort
    for (int i = 0; i < NUM_BUCKETS; i++) {
        if (bucketSizes[i] > 0) {
            for (int j = 0; j < bucketSizes[i] - 1; j++) {
                for (int k = 0; k < bucketSizes[i] - j - 1; k++) {
                    if (buckets[i][k] > buckets[i][k+1]) {
                        swap(&buckets[i][k], &buckets[i][k+1]);
                    }
                }
            }
        }
    }
    
    // Concatenate all buckets into output array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            output[index] = buckets[i][j];
            index++;
        }
    }
    
    // Copy output array back into input array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Main function to test Bucket Sort implementation
int main() {
    // Declare and initialize array
    int arr[] = {43, 12, 7, 32, 88, 54, 67, 31, 91, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);
    
    // Sort array using Bucket Sort algorithm
    bucketSort(arr, n);
    
    printf("Sorted Array:\n");
    printArray(arr, n);
    
    return 0;
}