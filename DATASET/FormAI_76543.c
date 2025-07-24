//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

// Define the maximum and minimum values in the array
#define MAX_VALUE 100
#define MIN_VALUE 0

// Define the size of the array
#define ARRAY_SIZE 20

// Define the number of buckets to be used
#define NUM_BUCKETS 10

// Bucket structure containing the array and the count
typedef struct Bucket {
    int* arr;
    int count;
} Bucket;

// Function to initialize the array with random values
void initArray(int* arr, int size) {
    int i;
    for(i=0; i<size; i++) {
        arr[i] = rand() % (MAX_VALUE-MIN_VALUE+1) + MIN_VALUE;
    }
}

// Function to print the contents of the array
void printArray(int* arr, int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to print the contents of the bucket
void printBucket(Bucket* b) {
    int i;
    for(i=0; i<b->count; i++) {
        printf("%d ", b->arr[i]);
    }
    printf("\n");
}

// Function to sort the array using bucket sort
void bucketSort(int* arr, int size) {
    Bucket buckets[NUM_BUCKETS];
    int i, j, k, min_val = MAX_VALUE, max_val = MIN_VALUE, bucket_index;

    // Find the minimum and maximum values in the array
    for(i=0; i<size; i++) {
        if(arr[i] < min_val) {
            min_val = arr[i];
        }
        if(arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Initialize the buckets
    for(i=0; i<NUM_BUCKETS; i++) {
        buckets[i].arr = (int*)malloc(sizeof(int)*ARRAY_SIZE);
        buckets[i].count = 0;
    }

    // Distribute the array elements into the buckets
    for(i=0; i<size; i++) {
        bucket_index = (arr[i]-min_val) / ((max_val-min_val+1) / NUM_BUCKETS);
        buckets[bucket_index].arr[buckets[bucket_index].count] = arr[i];
        buckets[bucket_index].count++;
    }

    // Sort each bucket using insertion sort
    for(i=0; i<NUM_BUCKETS; i++) {
        for(j=1; j<buckets[i].count; j++) {
            k = j;
            while(k>0 && buckets[i].arr[k]<buckets[i].arr[k-1]) {
                int temp = buckets[i].arr[k];
                buckets[i].arr[k] = buckets[i].arr[k-1];
                buckets[i].arr[k-1] = temp;
                k--;
            }
        }
    }

    // Merge the buckets back into the array
    k = 0;
    for(i=0; i<NUM_BUCKETS; i++) {
        for(j=0; j<buckets[i].count; j++) {
            arr[k] = buckets[i].arr[j];
            k++;
        }
    }

    // Free the memory used by the buckets
    for(i=0; i<NUM_BUCKETS; i++) {
        free(buckets[i].arr);
    }
}

int main() {
    int arr[ARRAY_SIZE];

    // Initialize the array with random values
    initArray(arr, ARRAY_SIZE);

    printf("Original array:\n");
    printArray(arr, ARRAY_SIZE);

    // Sort the array using bucket sort
    bucketSort(arr, ARRAY_SIZE);

    printf("Sorted array:\n");
    printArray(arr, ARRAY_SIZE);

    return 0;
}