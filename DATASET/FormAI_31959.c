//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 5

// Define the thread function
void *threadFunc(void *arg) {
    int tid = *((int*) arg);
    printf("Thread %d is starting\n", tid);
    printf("Thread %d is doing some work\n", tid);
    printf("Thread %d is finishing\n", tid);
    pthread_exit(NULL);
}

int main() {
    // Define an array of threads
    pthread_t threads[NUM_THREADS];

    // Define an array of integer arguments for the threads
    int args[NUM_THREADS];

    // Create all the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        args[i] = i;
        int result_code = pthread_create(&threads[i], NULL, threadFunc, &args[i]);
        if (result_code != 0) {
            printf("Error creating thread %d. Code %d\n", i, result_code);
            exit(-1);
        }
    }

    // Wait for all the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        int result_code = pthread_join(threads[i], NULL);
        if (result_code != 0) {
            printf("Error joining thread %d. Code %d\n", i, result_code);
            exit(-1);
        }
    }

    printf("All threads finished successfully\n");

    // Exit program
    return 0;
}