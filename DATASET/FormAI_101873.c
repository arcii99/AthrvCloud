//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKET_SIZE 10 // Define size of each bucket
#define NUM_BUCKETS 10 // Define number of buckets total

// Function to print out an array
void printArr(int *arr, int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if(i != size-1)
            printf(", ");
    }
    printf("]\n");
}

// Function to find max value in array
int getMax(int *arr, int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to perform bucket sort on an array
void bucketSort(int *arr, int size) {
    // Determine max value in array
    int max = getMax(arr, size);
    // Create an array of buckets
    int buckets[NUM_BUCKETS][BUCKET_SIZE];
    // Determine size of each bucket
    int bucketRange = (max+1)/NUM_BUCKETS;
    // Initialize each bucket size to 0
    int bucketSizes[NUM_BUCKETS] = {0};
    // Place each element in the correct bucket
    for(int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketRange;
        // Ensure that index doesn't go out of bounds
        if(bucketIndex >= NUM_BUCKETS) {
            bucketIndex = NUM_BUCKETS-1;
        }
        // Add element to bucket and increment bucket size
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }
    // Sort each individual bucket
    for(int i = 0; i < NUM_BUCKETS; i++) {
        for(int j = 0; j < bucketSizes[i]-1; j++) {
            for(int k = 0; k < bucketSizes[i]-j-1; k++) {
                if(buckets[i][k] > buckets[i][k+1]) {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k+1];
                    buckets[i][k+1] = temp;
                }
            }
        }
    }
    // Place elements back in original array in sorted order
    int index = 0;
    for(int i = 0; i < NUM_BUCKETS; i++) {
        for(int j = 0; j < bucketSizes[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int size = 20;
    int arr[size];
    // Fill array with random values between 1 and 100 (inclusive)
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
    printf("Original array:\n");
    printArr(arr, size);
    printf("Performing bucket sort...\n");
    bucketSort(arr, size);
    printf("Sorted array:\n");
    printArr(arr, size);
    return 0;
}