//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function to execute the threads
void *threadFunc(void *threadId) {
    int *id = (int*)threadId;
    printf("Thread %d executing\n", *id);
    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    // Initialize Mutex
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    // Initialize Condition Variable
    pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
    printf("Creating %d threads\n", NUM_THREADS);

    for (i = 0; i < NUM_THREADS; i++) {
        int *threadId = malloc(sizeof(int));
        *threadId = i;
        pthread_create(&threads[i], NULL, threadFunc, (void*) threadId);
    }

    // Wait for all threads to complete.
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);

    pthread_exit(NULL);
}