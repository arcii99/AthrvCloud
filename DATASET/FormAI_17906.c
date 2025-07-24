//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

// Struct to pass thread arguments
typedef struct {
    int thread_id;
    int iterations;
} thread_args;

// Function to be executed by the threads
void *thread_func(void *arguments) {
    thread_args *args = (thread_args *)arguments;
    int thread_id = args->thread_id;
    int iterations = args->iterations;

    printf("Thread %d started\n", thread_id);

    for (int i = 0; i < iterations; i++) {
        printf("Thread %d iteration %d\n", thread_id, i);
        // Simulate some work
        int x = rand() % 10000000;
        for (int j = 0; j < x; j++) {}
    }

    printf("Thread %d finished\n", thread_id);

    pthread_exit(NULL);
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Array to hold thread IDs
    pthread_t threads[NUM_THREADS];

    // Array to hold thread arguments
    thread_args args[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        args[i].thread_id = i;
        args[i].iterations = rand() % 10 + 1;
        pthread_create(&threads[i], NULL, thread_func, (void*)&args[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished\n");

    return 0;
}