//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *threadFunc(void *threadId) {
    int tid = *(int*)threadId;
    printf("Thread %d executing...\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, rc, tids[NUM_THREADS];
    for (i = 0; i < NUM_THREADS; i++) {
        tids[i] = i;
        rc = pthread_create(&threads[i], NULL, threadFunc, (void*)&tids[i]);
        if (rc) {
            printf("Error: unable to create thread %d\n", tids[i]);
            exit(-1);
        }
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads completed.\n");
    pthread_exit(NULL);
}