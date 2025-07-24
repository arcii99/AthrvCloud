//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the input array
#define ARRAY_SIZE 100

// Define the maximum and minimum values that can be in the array
#define MAX_VALUE 100
#define MIN_VALUE 1

// Define the number of buckets
#define NUM_BUCKETS 10

// Define the bucket size
#define BUCKET_SIZE (MAX_VALUE - MIN_VALUE) / NUM_BUCKETS

// Define the bucket structure
typedef struct Bucket {
    int *elements;   // the elements stored in the bucket
    int count;       // the number of elements in the bucket
    int size;        // the maximum capacity of the bucket
} Bucket;

// Define the bucket sort function
void bucketSort(int *array, int size) {
    Bucket buckets[NUM_BUCKETS]; // the array of buckets
    
    // Initialize each bucket
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i].size = BUCKET_SIZE;
        buckets[i].elements = (int*) malloc(buckets[i].size * sizeof(int));
        buckets[i].count = 0;
    }
    
    // Insert elements into buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = (array[i] - MIN_VALUE) / BUCKET_SIZE;
        
        // Double the bucket size if the bucket is full
        if (buckets[bucketIndex].count == buckets[bucketIndex].size) {
            buckets[bucketIndex].size *= 2;
            buckets[bucketIndex].elements = (int*) realloc(buckets[bucketIndex].elements, buckets[bucketIndex].size * sizeof(int));
        }
        
        // Insert the element into the bucket
        buckets[bucketIndex].elements[buckets[bucketIndex].count] = array[i];
        buckets[bucketIndex].count++;
    }
    
    // Sort each bucket
    for (int i = 0; i < NUM_BUCKETS; i++) {
        int *bucketArray = buckets[i].elements;
        int bucketSize = buckets[i].count;
        
        // Insertion sort
        for (int j = 1; j < bucketSize; j++) {
            int key = bucketArray[j];
            int k = j - 1;
            while (k >= 0 && bucketArray[k] > key) {
                bucketArray[k + 1] = bucketArray[k];
                k--;
            }
            bucketArray[k + 1] = key;
        }
    }
    
    // Concatenate the sorted buckets
    int arrayIndex = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        int *bucketArray = buckets[i].elements;
        int bucketSize = buckets[i].count;
        
        for (int j = 0; j < bucketSize; j++) {
            array[arrayIndex] = bucketArray[j];
            arrayIndex++;
        }
        
        // Free the memory used by each bucket's array
        free(bucketArray);
    }
}

int main() {
    // Generate random array of integers
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
    
    // Print original array
    printf("Original Array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Sort the array
    bucketSort(array, ARRAY_SIZE);
    
    // Print sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}