//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *threadFunc(void *threadID) {
    long tid;
    tid = (long)threadID;
    printf("Hello from thread #%ld!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for(t=0; t<NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, threadFunc, (void *)t);
        if (rc) {
            printf("ERROR; pthread_create() returned %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}