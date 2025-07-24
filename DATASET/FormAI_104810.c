//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int i, j;
    int bucket[n];
    for (i = 0; i < n; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++) {
        (bucket[arr[i]])++;
    }
    for (i = 0, j = 0; i < n; i++) {
        for (; bucket[i] > 0; (bucket[i])--) {
            arr[j++] = i;
        }
    }
}

int main() {
    int arr[] = {2, 3, 5, 5, 7, 8, 1, 4, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Input array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    bucketSort(arr, n);
    printf("\n\nArray after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}