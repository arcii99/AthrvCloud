//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Function to sort the array using bucket sort
void bucketSort(int arr[], int n, int bucket_size) {
    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Create buckets based on the maximum element
    int bucket_count = (max / bucket_size) + 1;
    int* buckets[bucket_count];
    for (int i = 0; i < bucket_count; i++)
        buckets[i] = (int*)malloc(bucket_size * sizeof(int));

    // Fill buckets with elements from the array
    for (int i = 0; i < n; i++) {
        int j = arr[i] / bucket_size;
        int k = 0;
        while (k < bucket_size && buckets[j][k] != 0)
            k++;
        buckets[j][k] = arr[i];
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < bucket_count; i++) {
        int* bucket = buckets[i];
        int size = 0;
        while (size < bucket_size && bucket[size] != 0)
            size++;

        for (int j = 1; j < size; j++) {
            int temp = bucket[j];
            int k = j - 1;
            while (k >= 0 && bucket[k] > temp) {
                bucket[k + 1] = bucket[k];
                k--;
            }
            bucket[k + 1] = temp;
        }
    }

    // Merge sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        int* bucket = buckets[i];
        int size = 0;
        while (size < bucket_size && bucket[size] != 0)
            size++;

        for (int j = 0; j < size; j++) {
            arr[index++] = bucket[j];
        }
    }

    // Free memory used by buckets
    for (int i = 0; i < bucket_count; i++)
        free(buckets[i]);
}

// Function to print the sorted array
void printArray(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = { 78, 17, 39, 26, 72, 94, 21, 12, 23, 68 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int bucket_size = 10;

    // Print original array
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Sort the array using bucket sort
    bucketSort(arr, n, bucket_size);

    // Print sorted array
    printArray(arr, n);

    return 0;
}