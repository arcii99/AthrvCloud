//FormAI DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // Array size
#define NUM_THREADS 4 // Number of threads

// Function to generate a random array
void generate_array(int* arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

// Function to perform bitwise AND operation on array elements
void* bitwise_and(void* thread_arg) {
    int* arr = (int*)thread_arg;
    int start = (int)(arr - &arr[0]); // Starting index
    int end = start + ARRAY_SIZE/NUM_THREADS; // Ending index
    for (int i = start; i < end; i++) {
        arr[i] = arr[i] & 0xFF; // Performing bitwise AND with 0xFF
    }
    pthread_exit(NULL);
}

int main() {
    int arr[ARRAY_SIZE];
    generate_array(arr, ARRAY_SIZE);

    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS][ARRAY_SIZE/NUM_THREADS];

    // Creating threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int start = i * ARRAY_SIZE/NUM_THREADS;
        int end = (i + 1) * ARRAY_SIZE/NUM_THREADS;
        for (int j = start; j < end; j++) {
            thread_args[i][j-start] = arr[j];
        }
        pthread_create(&threads[i], NULL, bitwise_and, (void*)thread_args[i]);
    }

    // Joining threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Printing results
    printf("Bitwise AND Operation:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}