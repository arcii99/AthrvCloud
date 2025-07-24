//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the MAX_VAL constant
#define MAX_VAL 1000

// Define the BUCKET_SIZE constant
#define BUCKET_SIZE 10

// Define the array length constant
#define ARRAY_LEN 20

/**
 * This function implements the C bucket sort algorithm for sorting integers.
 * It takes as input the array to be sorted and the length of the array.
 */
void c_bucket_sort(int arr[], int len) {
    // Create an array of buckets
    int buckets[BUCKET_SIZE][BUCKET_SIZE] = {0};

    // Iterate through the input array and insert each element into the appropriate bucket
    int val;
    for (int i = 0; i < len; i++) {
        val = arr[i] / BUCKET_SIZE;
        for (int j = 0; j < BUCKET_SIZE; j++) {
            if (val <= j) {
                buckets[j][i] = arr[i];
                break;
            }
        }
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 1; j < len; j++) {
            int key = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate the sorted buckets
    int k = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < len; j++) {
            if (buckets[i][j] != 0) {
                arr[k] = buckets[i][j];
                k++;
            }
        }
    }
}

int main() {
    // Initialize the random number generator seed
    srand(0);

    // Generate an array of random integers
    int arr[ARRAY_LEN];
    for (int i = 0; i < ARRAY_LEN; i++) {
        arr[i] = rand() % MAX_VAL;
    }

    // Display the unsorted array
    printf("Unsorted Array:\n");
    for (int i = 0; i < ARRAY_LEN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Call the bucket sort function to sort the array
    c_bucket_sort(arr, ARRAY_LEN);

    // Display the sorted array
    printf("Sorted Array:\n");
    for (int i = 0; i < ARRAY_LEN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}