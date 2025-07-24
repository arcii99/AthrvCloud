//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        (count[arr[i]])++;

    for (i = 0, j = 0; i < n; i++) {
        for (; count[i] > 0; (count[i])--)
            arr[j++] = i;
    }
}

int main() {
    int n = 10, i;
    int arr[] = {2, 0, 4, 7, 9, 1, 3, 5, 6, 8};

    printf("Unsorted Array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted Array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}