//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000  // Define size of input array
#define BUCKET_SIZE 10  // Define bucket size

// Function to perform bucket sort
void bucketSort(int array[], int n) {
    int i, j, k;
    int max_value = array[0];
    int min_value = array[0];
    int bucket_count;

    // Find maximum and minimum values in the array
    for (i = 1; i < n; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
        else if (array[i] < min_value) {
            min_value = array[i];
        }
    }

    // Calculate the total number of buckets needed
    bucket_count = (max_value - min_value) / BUCKET_SIZE + 1;

    // Create bucket array
    int** buckets = malloc(bucket_count * sizeof(int*));
    for (i = 0; i < bucket_count; i++) {
        buckets[i] = malloc(n * sizeof(int));
    }

    // Initialize the buckets with 0
    for (i = 0; i < bucket_count; i++) {
        for (j = 0; j < n; j++) {
            buckets[i][j] = 0;
        }
    }

    // Fill buckets with elements
    for (i = 0; i < n; i++) {
        j = (array[i] - min_value) / BUCKET_SIZE;
        buckets[j][i] = array[i];
    }

    // Sort each bucket individually and place back to original array
    k = 0;
    for (i = 0; i < bucket_count; i++) {
        for(j = 0; j < n; j++) {
            if (buckets[i][j] != 0) {
                array[k] = buckets[i][j];
                k++;
            }
        }
    }

    // Free memory of all buckets
    for (i = 0; i < bucket_count; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int i;
    int data[SIZE];

    // Generate random input array
    srand(time(0));
    for (i = 0; i < SIZE; i++) {
        data[i] = rand() % SIZE;
    }

    printf("Input array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Perform bucket sort on input array
    bucketSort(data, SIZE);

    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}