//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

// This is the function that will be called by each thread.
void* print_thread_id(void* thread_id)
{
    long tid = (long) thread_id;
    printf("Hello from thread %ld\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int i;

    // Create the threads
    for (i=0; i<NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, print_thread_id, (void*) (long) i);
        if (rc) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    // Wait for the threads to complete before exiting
    for (i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}