//FormAI DATASET v1.0 Category: Sorting ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10 // Size of the array to be sorted
#define NUM_THREADS 2 // Number of threads to use for sorting

int array[ARRAY_SIZE] = {5, 9, 3, 1, 2, 8, 4, 7, 6, 0}; // Array to be sorted

// Function for each thread to sort a partition of the array
void *sort_partition(void *start_void)
{
    int partition_start = *(int*)start_void;
    int partition_end = partition_start + (ARRAY_SIZE/NUM_THREADS) - 1;

    // Sort the partition using selection sort
    for (int i = partition_start; i <= partition_end; i++) {
        int min_index = i;
        for (int j = i+1; j <= partition_end; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS]; // Array to hold thread IDs
    int thread_args[NUM_THREADS]; // Array to hold arguments passed to each thread 

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i * (ARRAY_SIZE/NUM_THREADS); // Determine the starting index for each thread's partition
        pthread_create(&threads[i], NULL, sort_partition, &thread_args[i]); // Start each thread with the appropriate arguments
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Merge sorted partitions
    int merged_array[ARRAY_SIZE];
    int partition_sizes[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        partition_sizes[i] = ARRAY_SIZE/NUM_THREADS; // Determine the size of each partition
    }
    partition_sizes[NUM_THREADS-1] += ARRAY_SIZE % NUM_THREADS; // Account for any leftover elements in the last partition
    int partition_starts[NUM_THREADS];
    partition_starts[0] = 0; // The first partition starts at index 0
    for (int i = 1; i < NUM_THREADS; i++) {
        partition_starts[i] = partition_starts[i-1] + partition_sizes[i-1]; // Determine the starting index for each partition
    }
    int current_indices[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        current_indices[i] = partition_starts[i]; // Set the starting index for each partition to be its starting index
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int min_index = -1;
        int min_value;
        for (int j = 0; j < NUM_THREADS; j++) {
            if (current_indices[j] < partition_starts[j] + partition_sizes[j]) { // Check if the partition still has elements to be considered
                if (min_index == -1 || array[current_indices[j]] < min_value) {
                    min_index = j;
                    min_value = array[current_indices[j]];
                }
            }
        }
        merged_array[i] = min_value;
        current_indices[min_index]++;
    }

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", merged_array[i]);
    }
    printf("\n");

    return 0;
}