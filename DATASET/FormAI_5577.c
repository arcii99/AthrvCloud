//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// define the maximum and minimum element values
#define MAX_VALUE 100
#define MIN_VALUE 0

// define the size of each bucket
#define BUCKET_SIZE 10

// define the bucket struct
typedef struct Bucket {
    int size;
    int* values;
} Bucket;

// define the hash function
int hash(int value) {
    return (value - MIN_VALUE) / BUCKET_SIZE;
}

// define the insertion sort algorithm
void insertionSort(int* arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// define the bucket sort algorithm
void bucketSort(int* arr, int n) {
    int i, j, k;
    
    // create the array of buckets
    Bucket* buckets = (Bucket*) malloc(sizeof(Bucket) * (MAX_VALUE - MIN_VALUE) / BUCKET_SIZE);
    for (i = 0; i < (MAX_VALUE - MIN_VALUE) / BUCKET_SIZE; i++) {
        buckets[i].size = 0;
        buckets[i].values = (int*) malloc(sizeof(int) * n);
    }
    
    // add the elements to the appropriate buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = hash(arr[i]);
        buckets[bucketIndex].values[buckets[bucketIndex].size++] = arr[i];
    }
    
    // sort each bucket using insertion sort
    for (i = 0; i < (MAX_VALUE - MIN_VALUE) / BUCKET_SIZE; i++) {
        insertionSort(buckets[i].values, buckets[i].size);
    }
    
    // concatenate the sorted buckets into the original array
    k = 0;
    for (i = 0; i < (MAX_VALUE - MIN_VALUE) / BUCKET_SIZE; i++) {
        for (j = 0; j < buckets[i].size; j++) {
            arr[k++] = buckets[i].values[j];
        }
    }
}

// define the main function to test the bucket sort algorithm
int main() {
    int arr[] = {23, 45, 12, 56, 78, 34, 67, 89, 90, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // sort the array
    bucketSort(arr, n);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}