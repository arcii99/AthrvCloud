//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucket_sort(int *arr, int n) {
    int i, j, k;
    int max_val = arr[0];
    int *bucket;

    bucket = (int *) calloc(BUCKET_SIZE, sizeof(int));

    for (i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    for (i = 0, j = 0; i <= max_val && j < n; i++) {
        for (k = 0; k < bucket[i]; k++) {
            arr[j++] = i;
        }
    }

    free(bucket);
}

int main() {
    int arr[] = {8, 5, 2, 6, 9, 3, 1, 4, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}