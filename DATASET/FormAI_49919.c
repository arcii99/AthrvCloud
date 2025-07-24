//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_ELEMENTS 100

// Define the number of buckets
#define NUM_BUCKETS 10

// Define the size of each bucket
#define BUCKET_SIZE 10

// Define the maximum value of an element in the array
#define MAX_VALUE 1000

// Define a helper function that finds the maximum value in an array
int find_max(int arr[], int n) {
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    return max_value;
}

// Define the bucket sort function
void bucket_sort(int arr[], int n) {

    int max_value = find_max(arr, n);

    // Create an array of buckets
    int buckets[NUM_BUCKETS][BUCKET_SIZE] = {0};

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (int) (arr[i] / ((float) max_value + 1) * NUM_BUCKETS);
        int bucket_pos = 0;
        while (buckets[bucket_index][bucket_pos]) {
            bucket_pos++;
        }
        buckets[bucket_index][bucket_pos] = arr[i];
    }

    // Sort the buckets
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 1; j < BUCKET_SIZE; j++) { // Insertion sort
            int current_val = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > current_val) {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = current_val;
        }
    }

    // Copy the sorted elements back into the original array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < BUCKET_SIZE; j++) {
            if (buckets[i][j] != 0) {
                arr[index] = buckets[i][j];
                index++;
            }
        }
    }
}

int main() {

    // Generate a random array of integers
    int arr[MAX_ELEMENTS];
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    bucket_sort(arr, MAX_ELEMENTS);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}