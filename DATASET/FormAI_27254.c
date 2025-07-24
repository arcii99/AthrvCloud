//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *async(void *threadid) {
    long tid;
    tid = (long)threadid;
    printf("Async function running on thread %ld!\n", tid);
    for (int i = 0; i < 5; i++) {
        printf("Thread %ld is executing job %d.\n", tid, i);
        sleep(1); // simulate time-consuming operation
    }
    printf("Thread %ld has finished executing.\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Main: creating async thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, async, (void *)t);
        if (rc) {
            printf("Error: unable to create thread %d\n", rc);
            exit(-1);
        }
    }

    printf("Main: waiting for async threads to finish.\n");
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("Main: All async threads have completed.\n");
    pthread_exit(NULL);
}