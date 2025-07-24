//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum value in the array to be sorted
#define MAX_VALUE 1000

// Define the size of each bucket
#define BUCKET_SIZE 10

// Define the number of buckets required
#define NUM_BUCKETS (MAX_VALUE / BUCKET_SIZE) + 1

// Define the struct for each bucket
typedef struct Bucket {
    int count;
    int values[BUCKET_SIZE];
} Bucket;

// Define the main sorting function
void bucket_sort(int arr[], int size) {
    // Create an array of empty buckets
    Bucket buckets[NUM_BUCKETS] = { 0 };

    // Distribute the values from the input array into the buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        buckets[bucket_index].values[buckets[bucket_index].count++] = arr[i];
    }

    // Sort each individual bucket
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < buckets[i].count - 1; j++) {
            for (int k = 0; k < buckets[i].count - j - 1; k++) {
                if (buckets[i].values[k] > buckets[i].values[k + 1]) {
                    int temp = buckets[i].values[k];
                    buckets[i].values[k] = buckets[i].values[k + 1];
                    buckets[i].values[k + 1] = temp;
                }
            }
        }
    }

    // Merge the buckets back into the input array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].values[j];
        }
    }
}

// Define a helper function to print the contents of an array
void print_array(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Define the main function to test the implementation
int main() {
    // Create a sample array to be sorted
    int arr[] = { 85, 67, 98, 73, 24, 53, 52, 78, 22, 45, 10, 95, 87, 13, 82 };

    // Determine the size of the array
    int size = sizeof(arr) / sizeof(int);

    // Print the unsorted array
    printf("Unsorted array: ");
    print_array(arr, size);

    // Sort the array using bucket sort
    bucket_sort(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}