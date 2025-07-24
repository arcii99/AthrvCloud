//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10
#define RANGE 10

void printArray(int arr[]) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) printf("%d ", arr[i]);
    printf("\n");
}

int getMax(int arr[]) {
    int max = arr[0];
    int i;
    for (i = 1; i < ARRAY_SIZE; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void bucketSort(int arr[]) {
    int max = getMax(arr);
    int bucket[RANGE];
    int i, j;

    for (i = 0; i < RANGE; i++) bucket[i] = 0;

    for (i = 0; i < ARRAY_SIZE; i++) bucket[arr[i]]++;

    for (i = 0, j = 0; i < RANGE; i++) {
        while ((bucket[i]--) > 0) {
            arr[j++] = i;
        }
    }
}

int main() {
    int arr[ARRAY_SIZE] = {9, 5, 8, 3, 2, 1, 5, 3, 4, 2};
    printf("Original array: ");
    printArray(arr);

    printf("Sorted array using Bucket Sort: ");
    bucketSort(arr);
    printArray(arr);

    return 0;
}