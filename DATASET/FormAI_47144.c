//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10
#define NUM_THREADS 2

// Global variables for passing data between threads
int input[SIZE];
int output[SIZE];

// Thread function for performing the digital signal processing
void* dspThread(void* arg) {
    int *index = (int*) arg;

    printf("Thread %d started\n", *index);

    // Process data
    for (int i = 0; i < SIZE; i++) {
        output[i] = input[i] * 2;
    }

    printf("Thread %d finished\n", *index);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIndex[NUM_THREADS];

    // Populate input data
    for (int i = 0; i < SIZE; i++) {
        input[i] = rand() % 10;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        threadIndex[i] = i;
        pthread_create(&threads[i], NULL, dspThread, (void*) &threadIndex[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print input and output data
    printf("Input:\t");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");

    printf("Output:\t");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}