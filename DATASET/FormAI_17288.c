//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#define NUM_RANGE 10  // maximum number range
#define ARRAY_SIZE 20 // size of the input array

void bucketSort(int arr[], int n);
void printArray(int arr[], int n);

void bucketSort(int arr[], int n) {
    // create n empty buckets
    int buckets[NUM_RANGE] = {0};
    for(int i=0; i<n; i++) {
        (buckets[arr[i]])++;
    }
 
    // Sort using counting sort
    int index = 0;
    for (int i = 0; i < NUM_RANGE; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[ARRAY_SIZE] = {7, 3, 1, 9, 8, 4, 2, 6, 5, 0, 5, 3, 4, 2, 2, 8, 6, 0, 7, 9};
    printf("Unsorted array:\n");
    printArray(arr, ARRAY_SIZE);
    bucketSort(arr, ARRAY_SIZE);
    printf("Sorted array:\n");
    printArray(arr, ARRAY_SIZE);
    return 0;
}