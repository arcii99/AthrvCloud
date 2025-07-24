//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 10
#define MAX_VALUE 100

// Define bucket structure
typedef struct bucket {
    int value;
    struct bucket* next;
} Bucket;

// Function to insert element into bucket
void insert(Bucket** bucket, int value) {
    Bucket* newBucket = malloc(sizeof(Bucket));
    newBucket->value = value;
    newBucket->next = NULL;

    if (*bucket == NULL) {
        *bucket = newBucket;
    } else {
        Bucket* currentBucket = *bucket;
        while (currentBucket->next != NULL) {
            currentBucket = currentBucket->next;
        }
        currentBucket->next = newBucket;
    }
}

// Function to print bucket list
void printBucketList(Bucket* bucket) {
    if (bucket == NULL) {
        printf("[]");
        return;
    }

    printf("[ ");
    while (bucket != NULL) {
        printf("%d ", bucket->value);
        bucket = bucket->next;
    }
    printf("]");
}

// Function to print array
void printArray(int array[]) {
    printf("[ ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

// Bucket sort function
void bucketSort(int array[]) {
    Bucket* buckets[MAX_VALUE];

    // Initialize all buckets to NULL
    for (int i = 0; i < MAX_VALUE; i++) {
        buckets[i] = NULL;
    }

    // Insert elements into respective buckets
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int value = array[i];
        int index = value * MAX_VALUE / (MAX_VALUE + 1);
        insert(&buckets[index], value);
    }

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < MAX_VALUE; i++) {
        printBucketList(buckets[i]);
    }
    printf("\n");
}

// Main function for testing Bucket sort
int main() {
    int array[ARRAY_SIZE] = {85, 27, 62, 30, 72, 39, 67, 99, 22, 41};
    printf("Original array: ");
    printArray(array);
    bucketSort(array);
    return 0;
}