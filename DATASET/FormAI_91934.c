//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
    long tid = (long)threadid;
    printf("Hello from thread %ld\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Create threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        if (rc) {
            printf("ERROR: return code from pthread_create() was %d\n", rc);
            exit(-1);
        }
    }

    // Wait for threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR: return code from pthread_join() was %d\n", rc);
            exit(-1);
        }
        printf("Thread %ld has finished\n", t);
    }

    pthread_exit(NULL);
}