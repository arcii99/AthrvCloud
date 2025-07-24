//FormAI DATASET v1.0 Category: Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

void *thread_function(void *args);

int count = 0;

int main() {
    int i, status;
    pthread_t threads[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        status = pthread_create(&threads[i], NULL, thread_function, (void *) &i);
        if (status != 0) {
            printf("Thread creation failed: %d\n", status);
            exit(status);
        }
    }

    printf("Waiting for threads to finish...\n");
    for (i = 0; i < NUM_THREADS; i++) {
        status = pthread_join(threads[i], NULL);
        if (status != 0) {
            printf("Thread join failed: %d\n", status);
            exit(status);
        }
    }

    printf("Final count value: %d\n", count);

    return 0;
}

void *thread_function(void *args) {
    int i, tid, val;

    tid = *(int *) args;
    printf("Thread %d starting...\n", tid);

    for (i = 0; i < 1000000; i++) {
        val = count;
        val++;
        count = val;
    }

    printf("Thread %d ending...\n", tid);

    pthread_exit(NULL);
}