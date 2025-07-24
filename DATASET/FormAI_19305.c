//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4 // Number of threads to create

// Function executed by the threads
void *thread_func(void *thread_id)
{
    long id = (long)thread_id;
    printf("Thread %ld is starting...\n", id);

    // Do some work
    for (int i = 0; i < 5; i++) {
        printf("Thread %ld is working... (%d/5)\n", id, i + 1);
    }

    printf("Thread %ld is finished.\n", id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld...\n", t);
        rc = pthread_create(&threads[t], NULL, thread_func, (void *)t);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to complete
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads are finished.\n");
    pthread_exit(NULL);

    return 0;
}