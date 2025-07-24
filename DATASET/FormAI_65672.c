//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function to be executed by threads
void *printHello(void *threadID) {
    int tid = *(int*)threadID;
    printf("Hello from thread %d\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];
    int rc, t;

    for (t = 0; t < NUM_THREADS; t++) {
        threadIDs[t] = t;
        rc = pthread_create(&threads[t], NULL, printHello, (void *)&threadIDs[t]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    pthread_exit(NULL);
    return 0;
}