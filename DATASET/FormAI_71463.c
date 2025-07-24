//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    // Create the buckets
    int bucketCount = n;
    int largestNum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largestNum) {
            largestNum = arr[i];
        }
    }
    int *buckets = calloc(bucketCount, sizeof(int));
    // Add elements to the buckets
    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }
    // Sort the buckets
    int index = 0;
    for (int i = 0; i <= largestNum; i++) {
        int count = buckets[i];
        while (count > 0) {
            arr[index++] = i;
            count--;
        }
    }
    free(buckets);
}

int main() {
    int arr[] = {4, 2, 5, 1, 3, 9, 6, 8, 7, 0};
    int n = sizeof(arr) / sizeof(int);
    bucketSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}