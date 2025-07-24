//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int n) {
    // Create an array of buckets
    int buckets[SIZE][SIZE] = {0};

    // Create an array to store the count of elements in each bucket
    int count[SIZE] = {0};

    // Traverse through the array and add each element to the appropriate bucket
    for(int i = 0; i < n; i++) {
        int index = SIZE * arr[i] / (100 + 1); // Determine the index for the current element
        buckets[index][count[index]] = arr[i]; // Add the element to the bucket
        count[index]++; // Increase the count for the current bucket
    }

    // Traverse through the buckets and sort each bucket using insertion sort
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < count[i]; j++) {
            int temp = buckets[i][j];
            int k = j;
            while(k > 0 && temp < buckets[i][k - 1]) {
                buckets[i][k] = buckets[i][k - 1];
                k--;
            }
            buckets[i][k] = temp;
        }
    }

    // Traverse through the buckets and copy the elements back to the original array
    int index = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < count[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main() {
    int arr[] = {87, 45, 27, 74, 62, 15, 98, 67, 52, 30};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}