//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void BucketSort(int [], int);

void BucketSort(int arr[], int size) {
    int i, j;
    int count[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        count[i] = 0;
    }

    for (i = 0; i < size; i++) {
        (count[arr[i]])++;
    }

    for (i = 0, j = 0; i < MAX_SIZE; i++) {
        for (; count[i] > 0; (count[i])--) {
            arr[j++] = i;
        }
    }
}

int main() {
    int arr[] = { 10, 8, 6, 2, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    BucketSort(arr, size);

    printf("After sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}