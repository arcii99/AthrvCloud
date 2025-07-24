//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: detailed
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *threadFunc(void *arg) {
    int tid = *((int*)arg);    // cast void pointer back to int pointer and dereference
    printf("Thread %d printing.\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadArgs[NUM_THREADS];

    for(int i=0; i<NUM_THREADS; i++) {
        threadArgs[i] = i;
        pthread_create(&threads[i], NULL, threadFunc, &threadArgs[i]);
    }

    for(int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished execution.\n");

    return 0;
}