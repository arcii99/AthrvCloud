//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the maximum and minimum values to sort
#define MIN_VALUE 0
#define MAX_VALUE 1000

// Define the number of buckets to use
#define NUM_BUCKETS 10

// Define the size of each bucket
#define BUCKET_SIZE ((MAX_VALUE - MIN_VALUE) / NUM_BUCKETS)

// Define an array of buckets
int buckets[NUM_BUCKETS][BUCKET_SIZE];

// Define a function to print the contents of the buckets
void print_buckets() {
    printf("Buckets:\n");
    for (int i = 0; i < NUM_BUCKETS; i++) {
        printf("Bucket %d: ", i);
        for (int j = 0; j < BUCKET_SIZE; j++) {
            printf("%d ", buckets[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Generate an array of random values to sort
    int values[MAX_VALUE];
    for (int i = 0; i < MAX_VALUE; i++) {
        values[i] = rand() % (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
    }
    
    // Print the unsorted array
    printf("Unsorted Array:\n");
    for (int i = 0; i < MAX_VALUE; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
    
    // Sort the array using bucket sort
    for (int i = 0; i < MAX_VALUE; i++) {
        int bucketIndex = values[i] / BUCKET_SIZE;
        int bucketOffset = (values[i] % BUCKET_SIZE);
        buckets[bucketIndex][bucketOffset] = values[i];
    }
    
    // Print the sorted array
    printf("Sorted Array:\n");
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < BUCKET_SIZE; j++) {
            printf("%d ", buckets[i][j]);
        }
    }
    printf("\n");
    
    // Print the contents of the buckets
    print_buckets();
    
    return 0;
}