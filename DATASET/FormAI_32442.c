//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Ken Thompson
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4

void *thread_func(void* arg) {
    int tid = *((int*)arg);
    printf("Hello from thread %d\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int rc, i;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        rc = pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
        if (rc) {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("ERROR: Return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    printf("All threads have completed successfully\n");
    pthread_exit(NULL);
    return 0;
}