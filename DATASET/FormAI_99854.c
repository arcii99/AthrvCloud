//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *threadid) {
    int tid = *(int *)threadid;
    printf("Thread %d: Hello, world!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int tids[NUM_THREADS];
    void *status;

    // Set thread attributes
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Main: creating thread %d\n", i);
        tids[i] = i;
        int rc = pthread_create(&threads[i], &attr, print_hello, (void *)&tids[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_join(threads[i], &status);
        if (rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Main: thread %d completed with status %ld\n", i, (long)status);
    }

    // Clean up
    pthread_attr_destroy(&attr);
    pthread_exit(NULL);

    return 0;
}