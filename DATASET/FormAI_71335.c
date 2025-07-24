//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void* thread_function(void* thread_id) {

    int tid = *((int*) thread_id);
    printf("Thread %d started.\n", tid);

    pthread_exit(NULL);
}

int main() {

    int i;
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    printf("Creating %d threads...\n", NUM_THREADS);

    for(i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if(pthread_create(&threads[i], NULL, thread_function, (void*) &thread_ids[i])) {
            fprintf(stderr, "Error creating thread %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads created. Now waiting for them to complete...\n");

    for(i = 0; i < NUM_THREADS; i++) {
        if(pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread %d.\n", i);
            exit(EXIT_FAILURE);
        }
        printf("Thread %d completed.\n", i);
    }

    printf("All threads completed. Exiting...\n");

    pthread_exit(NULL);
}