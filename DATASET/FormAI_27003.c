//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define maximum size of array to be sorted
#define MAX_SIZE 1000

// Define maximum value that can be stored in array elements
#define MAX_VALUE 100

// Define number of buckets used for sorting
#define NUM_BUCKETS 10

// Define function to print out array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Define function to perform bucket sort
void bucketSort(int arr[], int size) {
    // Create array of empty buckets
    int buckets[NUM_BUCKETS][MAX_SIZE] = {0};
    // Create array to keep track of size of each bucket
    int bucket_sizes[NUM_BUCKETS] = {0};
    
    // Determine range of values in array
    int range = MAX_VALUE / NUM_BUCKETS;
    
    // Distribute elements of array into buckets based on value
    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / range;
        if (bucket_index >= NUM_BUCKETS) {
            bucket_index = NUM_BUCKETS - 1;
        }
        buckets[bucket_index][bucket_sizes[bucket_index]] = arr[i];
        bucket_sizes[bucket_index]++;
    }
    
    // Sort each individual bucket using insertion sort
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 1; j < bucket_sizes[i]; j++) {
            int temp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > temp) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = temp;
        }
    }
    
    // Concatenate sorted buckets back into original array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize array with random values
    int arr[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
    
    printf("Unsorted array:\n");
    printArray(arr, MAX_SIZE);
    
    // Sort array using bucket sort
    bucketSort(arr, MAX_SIZE);
    
    printf("Sorted array:\n");
    printArray(arr, MAX_SIZE);
    
    return 0;
}