//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *threadRunner(void *threadId) {
    long tid;
    tid = (long) threadId;
    printf("Thread %ld is running\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Create threads
    printf("Creating threads...\n");
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, threadRunner, (void *) t);
        if (rc) {
            printf("Error creating thread %ld\n", t);
            exit(-1);
        }
    }

    // Wait for threads to finish
    printf("Waiting for threads to finish...\n");
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("Error waiting for thread %ld\n", t);
            exit(-1);
        }
        printf("Thread %ld has finished\n", t);
    }

    pthread_exit(NULL);
}