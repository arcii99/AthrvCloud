//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5 // Number of threads we want to create

// This function will be the entry point for our threads
void *thread_func(void *thread_id) {
    long tid = (long) thread_id;
    printf("Thread %ld starting...\n", tid);
    printf("Thread %ld ending...\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    for(t=0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, thread_func, (void *) t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish before exiting main
    for(t=0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    
    printf("All threads completed.\n");
    pthread_exit(NULL);
}