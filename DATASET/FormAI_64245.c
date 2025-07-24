//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

/* A thread function. */
void *thread_func(void *arg) {
    int tid = *((int*)arg);
    printf("Thread %d is running\n",tid);
    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    /* Create all threads. */
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
    }

    /* Wait for all threads to finish. */
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed execution.\n");
    pthread_exit(NULL);
}