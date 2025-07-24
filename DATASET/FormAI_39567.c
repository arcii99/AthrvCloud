//FormAI DATASET v1.0 Category: System boot optimizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

void *bootOptimizer(void *threadID) {
    int tid = *(int*)threadID;
    printf("Thread %d optimizing system boot...\n", tid);
    sleep(3); // Simulate some work
    printf("Thread %d complete.\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];
    int rc, t;

    for (t = 0; t < NUM_THREADS; t++) {
        threadIDs[t] = t;
        printf("Creating thread %d...\n", t);
        rc = pthread_create(&threads[t], NULL, bootOptimizer, (void *)&threadIDs[t]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads complete. System boot optimized.\n");
    pthread_exit(NULL);
}