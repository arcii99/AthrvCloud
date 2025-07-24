//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n)
{
    // Create an array of 10 buckets
    int buckets[10][10], bucketSize[10];
    int i, j, k;

    // Initialize bucket sizes to 0
    for (i = 0; i < 10; i++) {
        bucketSize[i] = 0;
    }

    // Put items into the appropriate bucket
    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] / 10;
        buckets[bucketIndex][bucketSize[bucketIndex]++] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < 10; i++) {
        for (j = 1; j < bucketSize[i]; j++) {
            int key = buckets[i][j];
            k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate the sorted buckets into the original array
    int index = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < bucketSize[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main()
{
    // Initializing unsorted array
    int arr[] = { 32, 12, 3, 5, 11, 45, 80, 90, 74, 43 };

    int n = sizeof(arr) / sizeof(arr[0]);

    // Calling bucket sort function
    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}