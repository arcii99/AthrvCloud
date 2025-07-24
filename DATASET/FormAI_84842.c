//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1000 // range of values in the array to be sorted

void bucket_sort(int arr[], int size) {
    int i, j, idx;
    int *bucket_array[size];
    
    // initialize bucket array pointers as NULL
    for (i = 0; i < size; i++)
        bucket_array[i] = NULL;
    
    // allocate memory to each bucket array pointer
    for (i = 0; i < size; i++) {
        bucket_array[i] = (int*)malloc(sizeof(int)*size);
        for (j = 0; j < size; j++)
            bucket_array[i][j] = -1; // initialize each element as -1
    }

    // distribute elements into buckets based on their value
    for (i = 0; i < size; i++) {
        idx = arr[i] * size / MAX_VALUE;
        for (j = 0; bucket_array[idx][j] != -1; j++);
        bucket_array[idx][j] = arr[i];
    }

    // sort each bucket using insertion sort
    for (i = 0; i < size; i++) {
        for (j = 1; j < size && bucket_array[i][j] != -1; j++) {
            int key = bucket_array[i][j];
            int k = j - 1;
            while (k >= 0 && bucket_array[i][k] > key) {
                bucket_array[i][k+1] = bucket_array[i][k];
                k--;
            }
            bucket_array[i][k+1] = key;
        }
    }

    // concatenate all sorted buckets into single sorted array
    idx = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; bucket_array[i][j] != -1; j++)
            arr[idx++] = bucket_array[i][j];
    }
    
    // free memory allocated to bucket arrays
    for (i = 0; i < size; i++)
        free(bucket_array[i]);
}

int main() {
    int i, n;
    int arr[] = {37, 23, 94, 11, 53, 43, 89, 75, 69};
    n = sizeof(arr) / sizeof(int);

    printf("Original array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucket_sort(arr, n);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}