//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int arr[], int n)
{
    // Find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create buckets and initialize with 0
    int buckets[10] = { 0 };

    // Add elements into the buckets
    for (int i = 0; i < n; i++) {
        buckets[arr[i] / 10]++;
    }

    // Sort elements in the buckets
    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = (i * 10) + j;
        }
    }
}

int main()
{
    // Generate random array
    srand(time(0));
    int size = 20;
    int arr[size];
    printf("Unsorted Array: ");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    // Apply bucket sort
    bucketSort(arr, size);

    // Print sorted array
    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}