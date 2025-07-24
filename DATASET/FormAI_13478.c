//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *threadFunc(void *param) {
    int *tid_ptr = (int *)param;
    int tid = *tid_ptr;
    printf("Thread %d is running...\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int rc;
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        rc = pthread_create(&threads[i], NULL, threadFunc, &thread_args[i]);
        if (rc) {
            printf("Error creating thread %d - return code: %d\n", i, rc);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error joining thread %d - return code: %d\n", i, rc);
            exit(EXIT_FAILURE);
        }
    }

    pthread_exit(NULL);
    return 0;
}