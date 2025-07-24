//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int arr[], int n, int bucketSize) {
    int i, j, k;
    int minVal = arr[0];
    int maxVal = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        } else if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int bucketCount = (maxVal - minVal) / bucketSize + 1;
    int **buckets = (int **)malloc(bucketCount * sizeof(int *));
    for (i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc(bucketSize * sizeof(int));
    }

    int *bucketSizes = (int *)calloc(bucketCount, sizeof(int));

    for (i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - minVal) / bucketSize;
        if (bucketSizes[bucketIndex] == bucketSize) {
            printf("Bucket overflow! Increase bucket size.\n");
            continue;
        }

        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }

    k = 0;
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < bucketSizes[i]; j++) {
            arr[k] = buckets[i][j];
            k++;
        }
    }

    for (i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int n = 20;
    int arr[n];
    int i;

    printf("Unsorted Array:\n");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n, 10);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}