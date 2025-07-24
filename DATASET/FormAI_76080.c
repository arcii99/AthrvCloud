//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 4 // Number of threads
#define SIZE 100 // Size of the array

int array[SIZE]; // Shared array
pthread_mutex_t mutex; // Shared mutex

// Thread function
void* threadFunction(void* arg) {
    int* id = (int*) arg;
    int sum = 0;

    // Each thread takes a chunk of the array to sum
    int chunkSize = SIZE / THREADS;
    int start = (*id) * chunkSize;
    int end = start + chunkSize;

    // Perform the sum
    for (int i = start; i < end; i++) {
        pthread_mutex_lock(&mutex); // Acquire the mutex
        sum += array[i];
        pthread_mutex_unlock(&mutex); // Release the mutex
    }

    printf("Thread %d sum: %d\n", *id, sum);

    // Return the sum computed by the thread
    pthread_exit((void*) sum);
}

int main() {
    // Initialize the array with random values
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create the threads
    pthread_t threads[THREADS];
    int ids[THREADS];
    for (int i = 0; i < THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, threadFunction, &ids[i]);
    }

    // Join the threads and accumulate the results
    int totalSum = 0;
    for (int i = 0; i < THREADS; i++) {
        void* result;
        pthread_join(threads[i], &result);
        totalSum += (int) result;
    }

    printf("Total sum: %d\n", totalSum);

    // Cleanup the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}