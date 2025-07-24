//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

// function to execute by threads
void *thread_function(void *arg) {
    int thread_id = *((int *) arg);
    printf("Thread %d is starting execution...\n", thread_id);
    sleep(1);
    printf("Thread %d execution finished.\n", thread_id);
    pthread_exit(NULL); // exit thread
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    printf("Creating %d threads...\n", NUM_THREADS);

    // create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            printf("Error creating thread %d.\n", i);
            exit(-1);
        }
    }

    printf("Waiting for threads to finish...\n");

    // wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have terminated.\n");
    return 0;
}