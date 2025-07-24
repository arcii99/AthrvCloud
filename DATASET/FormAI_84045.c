//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1000

void bucketSort(int arr[], int n, int m) {
    int buckets[m];
    int i, j;
    for (i = 0; i < m; i++) {
        buckets[i] = 0;
    }
    for (i = 0; i < n; i++) {
        (buckets[arr[i]])++;
    }
    for (i = 0, j = 0; i < m; i++) {
        int k;
        for (k = buckets[i]; k > 0; k--) {
            arr[j++] = i;
        }
    }
}

int main() {
    int arr[] = {28, 55, 15, 84, 51, 60, 7, 56, 92, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    bucketSort(arr, n, MAX_VALUE);
    printf("\n\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}