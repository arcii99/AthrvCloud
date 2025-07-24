//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// C Bucket Sort Implementation
void bucketSort(int arr[], int n) {
    int i, j;
    int count[BUCKET_SIZE];
    for(i = 0; i < BUCKET_SIZE; ++i) {
        count[i] = 0;
    }
    
    // Counting the frequency of elements
    for(i = 0; i < n; ++i) {
        ++count[arr[i]];
    }
    
    // Sorting the elements
    for(i = 0, j = 0; i < BUCKET_SIZE; ++i) {
        for(; count[i] > 0; --count[i]) {
            arr[j++] = i;
        }
    }
}

int main() {
    // Random array of integers
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array:\n");
    for(int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    
    // Call the bucketSort function to sort the array
    bucketSort(arr, n);
    
    // Print the sorted array
    printf("\nSorted array:\n");
    for(int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}