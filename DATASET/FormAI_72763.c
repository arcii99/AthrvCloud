//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int i, j;
    int *bucket = (int *) malloc((n + 1) * sizeof(int));

    for(i = 0; i <= n; i++) {
        bucket[i] = 0;
    }

    for(i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    for(i = 0, j = 0; j <= n; j++) {
        while(bucket[j] > 0) {
            arr[i++] = j;
            bucket[j]--;
        }
    }
}

int main() {
    int arr[] = {54, 46, 83, 66, 95, 92, 43};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\n\nSorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}