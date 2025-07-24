//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *arg) {
    int tid = *((int*) arg);
    printf("Thread %d is running!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int tids[NUM_THREADS];

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        tids[i] = i;
        int rc = pthread_create(&threads[i], NULL, thread_func, (void*) &tids[i]);
        if (rc) {
            fprintf(stderr, "ERROR: pthread_create() failed (code %d)\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_join(threads[i], NULL);
        if (rc) {
            fprintf(stderr, "ERROR: pthread_join() failed (code %d)\n", rc);
            exit(-1);
        }
    }

    return 0;
}