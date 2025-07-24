//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *threadFunction(void *arg) {
    int tid = *((int *) arg);
    printf("Hello from thread %d\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadArgs[NUM_THREADS];
    int i;

    printf("Starting...\n");
    for (i = 0; i < NUM_THREADS; i++) {
        threadArgs[i] = i;
        if (pthread_create(&threads[i], NULL, threadFunction, &threadArgs[i]) != 0) {
            printf("Error creating thread %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error joining thread %d.\n", i);
            exit(EXIT_FAILURE);
        }
        printf("Thread %d joined.\n", i);
    }

    printf("All threads completed.\n");
    return 0;
}