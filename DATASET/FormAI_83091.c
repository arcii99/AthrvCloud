//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 5 // Define the number of threads

// Function that will be executed by each thread
void *thread_function(void *arg) {
    int *thread_id = arg;
    printf("Thread %d starting...\n", *thread_id);
    // Do some work here
    printf("Thread %d exiting...\n", *thread_id);
    pthread_exit(NULL); // Terminate thread
}

int main() {
    pthread_t thread[THREAD_COUNT];
    int thread_id[THREAD_COUNT];
    int i;

    // Create threads
    for (i = 0; i < THREAD_COUNT; i++) {
        thread_id[i] = i;
        if (pthread_create(&thread[i], NULL, thread_function, &thread_id[i])) {
            fprintf(stderr, "Error creating thread %d.\n", i);
            exit(1);
        }
    }

    // Wait for threads to finish
    for (i = 0; i < THREAD_COUNT; i++) {
        if (pthread_join(thread[i], NULL)) {
            fprintf(stderr, "Error joining thread %d.\n", i);
            exit(1);
        }
    }

    printf("All threads finished.\n");

    return 0;
}