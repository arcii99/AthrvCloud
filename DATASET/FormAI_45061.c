//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// This function will be run by each thread
void *threadFunction(void *threadId) {
    long tid = (long)threadId;
    printf("Thread %ld is running\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Create the threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, threadFunction, (void *)t);
        if (rc) {
            printf("Error: unable to create thread\n");
            exit(-1);
        }
    }

    // Wait for all the threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads finished\n");
    pthread_exit(NULL);
}