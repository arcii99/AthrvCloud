//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n, int max) {
    int i, j;
    int count[max];
    for (i = 0; i < max; i++) {
        count[i] = 0;
    }
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (i = 0, j = 0; i < max; i++) {
        while (count[i] > 0) {
            arr[j++] = i;
            count[i]--;
        }
    }
}

int main() {
    int arr[] = {3, 6, 1, 8, 4, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 11; // maximum value of an element
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n, max);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}