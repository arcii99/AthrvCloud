//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int len) {
    printf("[ ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void bucketSort(int* arr, int len) {
    int i, j;
    int count[len];
    for (i = 0; i < len; i++) {
        count[i] = 0;
    }
    
    for (i = 0; i < len; i++) {
        (count[arr[i]])++;
    }

    for (i = 0, j = 0; i < len; i++) {
        for (; count[i] > 0; (count[i])--) {
            arr[j++] = i;
        }
    }
}

int main() {
    int arr[] = {4, 2, 10, 7, 5, 3, 8, 1, 6, 9};
    int len = sizeof(arr) / sizeof(int);

    printf("Before sorting: ");
    printArray(arr, len);

    bucketSort(arr, len);

    printf("After sorting: ");
    printArray(arr, len);
}