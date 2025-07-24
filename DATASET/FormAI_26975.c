//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum number of elements and buckets
#define MAX_ELEMENTS 100
#define NUM_BUCKETS 10
#define MAX_DIGITS 10

// Define the structure of each bucket
typedef struct {
    int size;
    int data[MAX_ELEMENTS];
} Bucket;

// Declare functions
void bucketSort(int[], const int);
void printArray(int[], const int);
void printBuckets(Bucket[], const int);
void insertionSort(Bucket*);

int main() {
    // Initialize the array with random integers from 0 to 99
    int arr[MAX_ELEMENTS];
    srand(0);
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        arr[i] = rand() % 100;
    }

    // Print the initial array
    printf("Initial array: \n");
    printArray(arr, MAX_ELEMENTS);

    // Sort the array using bucket sort
    bucketSort(arr, MAX_ELEMENTS);

    // Print the sorted array
    printf("\nSorted array: \n");
    printArray(arr, MAX_ELEMENTS);

    return 0;
}

void bucketSort(int arr[], const int n) {
    int i, j, k;
    Bucket bucket[NUM_BUCKETS]; // Declare buckets
    int divisor = 1; // Define divisor for digit extraction
    
    // Loop through each digit and sort by radix
    for (i = 0; i < MAX_DIGITS; i++) {
        // Initialize each bucket with size 0
        for (j = 0; j < NUM_BUCKETS; j++) {
            bucket[j].size = 0;
        }

        // Place each element in the appropriate bucket
        for (j = 0; j < n; j++) {
            int bucketIndex = (arr[j] / divisor) % NUM_BUCKETS;
            bucket[bucketIndex].data[bucket[bucketIndex].size++] = arr[j];
        }

        // Sort each non-empty bucket by insertion sort
        for (j = 0; j < NUM_BUCKETS; j++) {
            if (bucket[j].size > 1) {
                insertionSort(&bucket[j]);
            }
        }

        // Reset the array index and place the elements back into the array
        k = 0;
        for (j = 0; j < NUM_BUCKETS; j++) {
            memcpy(&arr[k], &bucket[j].data[0], bucket[j].size * sizeof(int));
            k += bucket[j].size;
        }
        
        // Multiply the divisor by 10 to extract the next digit
        divisor *= NUM_BUCKETS;
    }
}

void insertionSort(Bucket* bucket) {
    int i, j, temp;
    for (i = 1; i < bucket->size; i++) {
        temp = bucket->data[i];
        for (j = i - 1; j >= 0 && temp < bucket->data[j]; j--) {
            bucket->data[j + 1] = bucket->data[j];
        }
        bucket->data[j + 1] = temp;
    }
}

void printArray(int arr[], const int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printBuckets(Bucket bucket[], const int n) {
    for (int i = 0; i < n; i++) {
        printf("Bucket %d: ", i);
        for (int j = 0; j < bucket[i].size; j++) {
            printf("%d ", bucket[i].data[j]);
        }
        printf("\n");
    }
}