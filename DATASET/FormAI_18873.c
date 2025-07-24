//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *helloThread(void *threadID) {
    int tid = *(int*)threadID;
    printf("Hello from thread %d!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];
    int rc, t;

    // create threads
    for (t = 0; t < NUM_THREADS; t++) {
        threadIDs[t] = t;
        rc = pthread_create(&threads[t], NULL, helloThread, &threadIDs[t]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    // wait for threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads have finished execution.\n");

    pthread_exit(NULL);
    return 0;
}