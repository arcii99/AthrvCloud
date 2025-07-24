//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *arg) {
    int thread_num = *(int *) arg;
    printf("Thread %d is running\n", thread_num);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int rc, t;

    for (t = 0; t < NUM_THREADS; t++) {
        thread_args[t] = t;
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, thread_func, (void *) &thread_args[t]);
        if (rc) {
            printf("Error: Unable to create thread %d, error code %d\n", t, rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads completed successfully\n");
    return 0;
}