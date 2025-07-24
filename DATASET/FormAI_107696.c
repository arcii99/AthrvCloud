//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    // Create size number of buckets
    int buckets[size];
    memset(buckets, 0, sizeof(buckets));
    int i, j, k;

    // Fill the buckets with the frequency of numbers
    for (i = 0; i < size; i++) {
        (buckets[arr[i]])++;
    }

    int index = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < buckets[i]; j++) {
            arr[index] = i;
            index++;
        }
    }
}

void bucketSortRecursive(int arr[], int size, int maxVal) {
    int i;
    if (size == 0 || maxVal == 0) {
        return;
    }

    // Divide the array into size buckets
    int buckets[size];
    memset(buckets, 0, sizeof(buckets));

    for (i = 0; i < size; i++) {
        (buckets[arr[i]])++;
    }

    int index = 0;
    for (i = 0; i < size; i++) {
        int j;
        for (j = 0; j < buckets[i]; j++) {
            arr[index] = i;
            index++;
        }
    }

    printArray(arr, size);

    // Call the function recursively for each bucket
    int half = (maxVal + 1) / 2;
    int arr1[half];
    int arr2[half];

    memcpy(arr1, arr, half * sizeof(int));
    memcpy(arr2, arr + half, half * sizeof(int));

    bucketSortRecursive(arr1, half, half);
    bucketSortRecursive(arr2, half, maxVal - half);
}

int main() {
    int arr[SIZE] = { 9, 6, 8, 7, 4, 5, 2, 3, 1, 0 };
    int i;

    printf("Input Array: ");
    printArray(arr, SIZE);

    printf("\nBucket Sort: ");
    bucketSort(arr, SIZE);
    printArray(arr, SIZE);

    printf("\nBucket Sort (Recursive): ");
    bucketSortRecursive(arr, SIZE, SIZE - 1);

    return 0;
}