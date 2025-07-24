//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n, int maxVal) {
    int i, j; 
    int *buckets;
 
    if ((buckets = calloc(maxVal + 1, sizeof(int))) == NULL)
        exit(EXIT_FAILURE);
 
    for (i = 0; i < n; i++)
        buckets[arr[i]]++;
 
    for (i = 0, j = 0; j <= maxVal; j++) {
        while (buckets[j]-- > 0) {
            arr[i++] = j;
        }
    }
 
    free(buckets);
}

int main() {
    int arr[] = { 5, 2, 8, 3, 10, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxVal = 10;
    int i;
 
    printf("Before sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
 
    bucketSort(arr, n, maxVal);
 
    printf("\nAfter sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}