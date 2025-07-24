//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
}

void bucketSort(int arr[], int n) {
    int i, j;
    int count[n];
    for (i=0; i < n; i++)
        count[i] = 0;
    for (i=0; i < n; i++)
        (count[arr[i]])++;
    for (i=0,j=0; i < n; i++) {
        for (; count[i]>0; (count[i])--) {
            arr[j++] = i;
        }
    }
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array:\n");
    printArray(arr,n);
    bucketSort(arr,n);
    printf("\nSorted array:\n");
    printArray(arr,n);
    return 0;
}