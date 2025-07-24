//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *threadFunction(void *arg) {
    int threadID = *((int*) arg);
    printf("Thread %d is starting\n", threadID);
    sleep(1);
    printf("Thread %d is exiting\n", threadID);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    pthread_t threads[NUM_THREADS];
    int threadID[NUM_THREADS];
    int i;

    printf("Creating %d threads:\n", NUM_THREADS);
    for (i = 0; i < NUM_THREADS; i++) {
        threadID[i] = i;
        printf("Creating Thread %d\n", i);
        pthread_create(&threads[i], NULL, threadFunction, &threadID[i]);
    }

    printf("Waiting for threads to finish...\n");
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d finished\n", i);
    }

    printf("All threads finished, program exiting\n");
    return 0;
}