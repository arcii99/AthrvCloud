//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int *arr, int n, int size) {
    int i, j;
    int count[size]; 
    for (i = 0; i < size; ++i) { 
        count[i] = 0; 
    }
    for (i = 0; i < n; ++i) { 
        ++count[arr[i]]; 
    }
    for (i = 0, j = 0; i < size; ++i) { 
        for (; count[i] > 0; --count[i]) { 
            arr[j++] = i; 
        } 
    } 
} 

int main() {
    int arr[] = { 7, 3, 3, 4, 8, 2, 2, 4, 9, 1, 2, 10, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Before sorting: \n");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n, 11);

    printf("After sorting: \n");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}