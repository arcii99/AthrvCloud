//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4 // Number of threads
#define ARRAY_SIZE 20000000 // Size of array to be sorted
#define MAX_NUMBER 1000 // Maximum value of random numbers generated

int array[ARRAY_SIZE]; // Array to be sorted

// Function to generate random numbers
void *generate_random_numbers(void *thread_id) {
    int i;
    int start = *((int *) thread_id) * (ARRAY_SIZE / NUM_THREADS);
    int end = start + (ARRAY_SIZE / NUM_THREADS);

    for (i = start; i < end; i++) {
        array[i] = rand() % MAX_NUMBER;
    }

    pthread_exit(NULL);
}

// Function to sort the array
void *sort_array(void *thread_id) {
    int i;
    int start = *((int *) thread_id) * (ARRAY_SIZE / NUM_THREADS);
    int end = start + (ARRAY_SIZE / NUM_THREADS);

    for (i = start; i < end; i++) {
        int j, temp;
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize random seed
    srand(time(NULL));

    // Fill array with random numbers using multiple threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, generate_random_numbers, (void *) &thread_ids[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Sort array using multiple threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, sort_array, (void *) &thread_ids[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print sorted array
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    pthread_exit(NULL);
}