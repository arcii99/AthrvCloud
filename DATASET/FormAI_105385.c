//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bucketsort algorithm
void bucketSort(int *array, int n)
{
    // Create n empty array (buckets)
    int *bucket = calloc(n, sizeof(int));

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        bucket[array[i]]++;
    }

    // Merge the buckets
    for (int i = 0, j = 0; j < n; j++) {
        while (bucket[i]-- > 0) {
            array[j++] = i;
        }
    }
    free(bucket);
}

// Utility function to print array
void printArray(int *array, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {31, 71, 20, 11, 9, 7, 33, 19, 8};
    int n = sizeof(array) / sizeof(array[0]);
    printf("Original array:\n");
    printArray(array, n);

    bucketSort(array, n);
    printf("Sorted array:\n");
    printArray(array, n);

    return 0;
}