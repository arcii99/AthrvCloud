//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum and minimum values of the input array
#define MAX_VALUE 100
#define MIN_VALUE 0

// Define the number of buckets
#define NUM_BUCKETS 5

// Define the size of each bucket
#define BUCKET_SIZE ((MAX_VALUE - MIN_VALUE) / NUM_BUCKETS)

// Define the bucket struct
typedef struct bucket {
    int *values;
    int size;
} bucket;

// Define the bucket sort function
void bucket_sort(int arr[], int n) {

    // Initialize the buckets
    bucket buckets[NUM_BUCKETS];
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i].values = malloc(sizeof(int) * n);
        buckets[i].size = 0;
    }

    // Distribute the values into the buckets
    for (int i = 0; i < n; i++) {
        int value = arr[i];
        int bucket_index = value / BUCKET_SIZE;

        if (bucket_index >= NUM_BUCKETS) {
            bucket_index = NUM_BUCKETS - 1;
        }

        buckets[bucket_index].values[buckets[bucket_index].size] = value;
        buckets[bucket_index].size++;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 1; j < buckets[i].size; j++) {
            int temp = buckets[i].values[j];
            int k;

            for (k = j - 1; k >= 0 && buckets[i].values[k] > temp; k--) {
                buckets[i].values[k+1] = buckets[i].values[k];
            }

            buckets[i].values[k+1] = temp;
        }
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[index] = buckets[i].values[j];
            index++;
        }
    }

    // Free the memory used by the buckets
    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i].values);
    }
}

// Test the bucket sort function
int main() {
    int arr[10] = {72, 45, 2, 21, 17, 98, 33, 87, 22, 5};

    printf("Original array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, 10);

    printf("\nSorted array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}