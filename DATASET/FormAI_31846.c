//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *thread_arg) {
    int thread_id = *(int*)thread_arg;
    printf("Thread %d: Hello World!\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i, rc;

    // Create all threads
    for(i=0; i<NUM_THREADS; ++i) {
        thread_args[i] = i;
        rc = pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
        if(rc) {
            fprintf(stderr, "Error: Unable to create thread %d, rc=%d\n", i, rc);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for(i=0; i<NUM_THREADS; ++i) {
        rc = pthread_join(threads[i], NULL);
        if(rc) {
            fprintf(stderr, "Error: Unable to join thread %d, rc=%d\n", i, rc);
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}