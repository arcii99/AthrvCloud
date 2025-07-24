//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of buckets
const int MAX_BUCKETS = 100;

// Define a bucket
typedef struct Bucket {
    int count;
    int* values;
} Bucket;

int* bucketSort(int arr[], int size, int maxVal) {
    // Create and initialize the buckets
    Bucket* buckets = (Bucket*)malloc(sizeof(Bucket) * MAX_BUCKETS);
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(sizeof(int) * size);
    }

    // Add each element to the correct bucket
    for (int i = 0; i < size; i++) {
        int bucketIdx = arr[i] * MAX_BUCKETS / (maxVal + 1);
        buckets[bucketIdx].values[buckets[bucketIdx].count] = arr[i];
        buckets[bucketIdx].count++;
    }

    // Sort each bucket
    int* sortedArr = (int*)malloc(sizeof(int) * size);
    int idx = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        insertSort(buckets[i].values, buckets[i].count);
        for (int j = 0; j < buckets[i].count; j++) {
            sortedArr[idx++] = buckets[i].values[j];
        }
    }

    // Free the memory used by the buckets
    for (int i = 0; i < MAX_BUCKETS; i++) {
        free(buckets[i].values);
    }
    free(buckets);

    return sortedArr;
}

int main() {
    // Example usage
    int arr[] = {7, 3, 9, 4, 1, 2, 8, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    int maxVal = 9;
  
    int* sortedArr = bucketSort(arr, size, maxVal);

    // Print the sorted array
    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);
    }

    // Free the memory used by the sorted array
    free(sortedArr);

    return 0;
}

// Insertion sort for sorting the values in a bucket
void insertSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int val = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > val) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
}