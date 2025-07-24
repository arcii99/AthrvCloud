//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int n) {
    // Create an array of buckets
    int buckets[BUCKET_SIZE][n];
    int bucketIndex[BUCKET_SIZE] = {0};
    int i, j, k;

    // Find the maximum value
    int maxValue = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    // Put values into buckets
    int divider = (maxValue / BUCKET_SIZE) + 1;
    for (i = 0; i < n; i++) {
        int bucket = arr[i] / divider;
        int index = bucketIndex[bucket];
        buckets[bucket][index] = arr[i];
        bucketIndex[bucket]++;
    }

    // Sort values in each bucket
    for (i = 0; i < BUCKET_SIZE; i++) {
        int *bucket = buckets[i];
        int bucketSize = bucketIndex[i];
        for (j = 1; j < bucketSize; j++) {
            int key = bucket[j];
            k = j - 1;
            while (k >= 0 && bucket[k] > key) {
                bucket[k + 1] = bucket[k];
                k--;
            }
            bucket[k + 1] = key;
        }
    }

    // Combine buckets into sorted array
    int index = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        int *bucket = buckets[i];
        int bucketSize = bucketIndex[i];
        for (j = 0; j < bucketSize; j++) {
            arr[index] = bucket[j];
            index++;
        }
    }
}

int main() {
    printf("Let's sort some numbers with Bucket Sort!\n");

    int arr[] = {7, 3, 9, 4, 2, 8, 5, 1, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    printf("Wow, that was quick! Pretty cool, huh?\n");

    return 0;
}