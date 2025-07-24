//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 20
#define MAX_BUCKET_SIZE 10

void bucketSort(int arr[], int n) {
    int i, j;
    int count[MAX_BUCKET_SIZE] = {0};
    int bucket[MAX_BUCKET_SIZE][MAX_ARRAY_SIZE];

    for (i = 0; i < n; ++i) {
        ++count[arr[i]];
        for (j = 0; j < MAX_BUCKET_SIZE; ++j) {
            bucket[j][count[j]-1] = arr[i];
        }
    }

    for (i = 0, j = 0; j < MAX_BUCKET_SIZE; ++j) {
        for (int k = 0; k < count[j]; ++k) {
            arr[i++] = bucket[j][k];
        }
    }
}

int main() {
    int arr[MAX_ARRAY_SIZE] = {5, 9, 3, 1, 8, 6, 4, 5, 2, 0, 7, 9, 3, 4, 8, 1, 6, 2, 7, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before Sorting:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\n\nAfter Sorting:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}