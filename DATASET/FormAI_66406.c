//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum value that can be sorted
#define MAX_VALUE 100

// define the size of each bucket
#define BUCKET_SIZE 5

// function to swap two values
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to perform bucket sort
void bucketSort(int arr[], int n) {
    // create an array of buckets
    int buckets[MAX_VALUE / BUCKET_SIZE][BUCKET_SIZE];

    // initialize each bucket with 0
    memset(buckets, 0, sizeof(buckets));

    // distribute the elements of the input array to the buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        int bucketPos = buckets[bucketIndex][0];
        buckets[bucketIndex][bucketPos + 1] = arr[i];
        buckets[bucketIndex][0]++;
    }

    // sort each bucket separately using insertion sort
    for (int i = 0; i < MAX_VALUE / BUCKET_SIZE; i++) {
        for (int j = 1; j <= buckets[i][0]; j++) {
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > buckets[i][k + 1]) {
                swap(&buckets[i][k], &buckets[i][k + 1]);
                k--;
            }
        }
    }

    // concatenate the sorted elements of the buckets
    int index = 0;
    for (int i = 0; i < MAX_VALUE / BUCKET_SIZE; i++) {
        for (int j = 1; j <= buckets[i][0]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// main function
int main() {
    // initialize an array of random integers
    int arr[] = {27, 11, 15, 21, 12, 17, 18, 14, 23, 38, 47, 52, 43, 32, 25, 31, 29, 34, 45, 41};

    // calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // perform bucket sort
    bucketSort(arr, n);

    // print the sorted array
    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}