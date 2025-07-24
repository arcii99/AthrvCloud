//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

/* function to print an array */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

/* function for bucket sort */
void bucketSort(int arr[], int size) {
    int i, j, k;
    int buckets[BUCKET_SIZE];

    /* initialize all buckets to 0 */
    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = 0;
    }

    /* fill the buckets */
    for (i = 0; i < size; i++) {
        buckets[arr[i]]++;
    }

    /* sort the elements */
    for (i = 0, j = 0; i < BUCKET_SIZE; i++) {
        for (k = buckets[i]; k > 0; k--) {
            arr[j++] = i;
        }
    }
}

/* driver program */
int main() {
    int arr[] = {5, 2, 7, 3, 9, 4, 1, 8, 6, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("\nSorted Array: ");
    printArray(arr, size);

    return 0;
}