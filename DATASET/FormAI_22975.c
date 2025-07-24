//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[arr[i]]++;

    for (i = 0, j = 0; i < n; i++) {
        for (; count[i] > 0; (count[i])--)
            arr[j++] = i;
    }
}

int main() {
    int i, n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements separated by space. \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}