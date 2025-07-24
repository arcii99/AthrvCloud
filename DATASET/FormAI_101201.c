//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 // size of array to be sorted


// function to swap elements of array
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


// function to sort array using bucket sort
void bucket_sort(int arr[], int n) {
    // create an array of buckets
    int bucket[n];
    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    // fill the buckets
    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // sort elements of each bucket
    for (int i = 0, j = 0; i < n; i++) {
        while (bucket[i] > 0) {
            arr[j++] = i;
            bucket[i]--;
        }
    }
}


// main function to test the bucket sort implementation
int main() {
    int arr[SIZE] = {5, 1, 3, 2, 5, 4, 6, 8, 9, 7};
    
    printf("Unsorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, SIZE);

    printf("\nSorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}