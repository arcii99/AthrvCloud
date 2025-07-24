//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bucketSort(int arr[], int size)
{
    // Create buckets
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int divider = (max - min) / size + 1;

    int numBuckets = (max - min) / divider + 1;

    int **buckets = (int **)malloc(sizeof(int *) * numBuckets);
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * size);
    }

    // Insert elements into buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = (arr[i] - min) / divider;
        buckets[bucketIndex][i] = arr[i];
    }

    // Sort buckets and get sorted array
    int k = 0;
    for (int i = 0; i < numBuckets; i++) {
        int bucketSize = size;
        for (int j = 0; j < bucketSize; j++) {
            int temp = buckets[i][j];
            for (int l = j + 1; l < bucketSize; l++) {
                if (buckets[i][l] < temp) {
                    temp = buckets[i][l];
                    buckets[i][l] = buckets[i][j];
                    buckets[i][j] = temp;
                }
            }
            if (buckets[i][j] != 0) {
                arr[k++] = buckets[i][j];
            }
        }
    }

    // Free memory
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main()
{
    srand(time(NULL));
    int n = 10;
    int arr[10];

    // Generate random array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Unsorted array: ");
    printArray(arr, n);

    // Sort array with bucket sort
    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}