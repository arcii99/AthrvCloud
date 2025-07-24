//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>

void bucketSort(int arr[], int n, int max) {
    int i, j, k;
    int buckets[max];

    for (i = 0; i < max; i++) {
        buckets[i] = 0;
    }

    for (i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    for (i = 0, j = 0; i < max; i++) {
        for (k = buckets[i]; k > 0; k--) {
            arr[j++] = i;
        }
    }
}

int main() {
    int arr[] = {3, 1, 5, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 6; // maximum value in the array

    bucketSort(arr, n, max);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}