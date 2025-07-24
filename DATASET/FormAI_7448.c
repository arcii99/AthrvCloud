//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the input array
#define MAX_INPUT_SIZE 100

// Define the maximum value an element in the input array can take
#define MAX_ELEMENT_VALUE 100

// Define the number of buckets
#define NUM_BUCKETS 5

// Retrieve the maximum value in the input array
int getMaxValue(int arr[], int arr_length) {
    int max_val = arr[0];
    for(int i = 1; i < arr_length; i++) {
        if(arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

// Perform bucket sort on the input array
void bucketSort(int arr[], int arr_length) {

    // Create buckets to hold elements
    int buckets[NUM_BUCKETS][MAX_INPUT_SIZE];

    // Initialize the size of each bucket to zero
    int bucket_sizes[NUM_BUCKETS];
    for(int i = 0; i < NUM_BUCKETS; i++) {
        bucket_sizes[i] = 0;
    }

    // Determine the range of values in the input array
    int max_val = getMaxValue(arr, arr_length);
    int range = (max_val / NUM_BUCKETS) + 1;

    // Place each element into its appropriate bucket
    for(int i = 0; i < arr_length; i++) {
        int bucket_index = arr[i] / range;
        if(bucket_index >= NUM_BUCKETS) {
            bucket_index = NUM_BUCKETS - 1;
        }
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }

    // Sort each bucket individually using insertion sort
    for(int i = 0; i < NUM_BUCKETS; i++) {
        for(int j = 1; j < bucket_sizes[i]; j++) {
            int curr_val = buckets[i][j];
            int k = j - 1;
            while(k >= 0 && buckets[i][k] > curr_val) {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = curr_val;
        }
    }

    // Combine the sorted buckets into the final array
    int idx = 0;
    for(int i = 0; i < NUM_BUCKETS; i++) {
        for(int j = 0; j < bucket_sizes[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

// Entry point of the program
int main() {

    // Initialize the input array with random values
    int input_array[MAX_INPUT_SIZE];
    int input_array_length = 0;
    srand(time(NULL));
    for(int i = 0; i < MAX_INPUT_SIZE; i++) {
        input_array[i] = rand() % MAX_ELEMENT_VALUE + 1;
        input_array_length++;
    }

    // Print the original input array
    printf("Original Input Array: ");
    for(int i = 0; i < input_array_length; i++) {
        printf("%d ", input_array[i]);
    }
    printf("\n");

    // Sort the input array using bucket sort
    bucketSort(input_array, input_array_length);

    // Print the sorted input array
    printf("Sorted Input Array: ");
    for(int i = 0; i < input_array_length; i++) {
        printf("%d ", input_array[i]);
    }
    printf("\n");

    return 0;
}