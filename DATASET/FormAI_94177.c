//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *arg) {
    int thread_id;
    thread_id = *((int *) arg);
    printf("Thread %d is running\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    int i, rc;
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    // Initialize thread attributes
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        rc = pthread_create(&threads[i], &attr, thread_function, (void *) &thread_args[i]);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }

    // Deallocate thread attributes
    pthread_attr_destroy(&attr);

    // Wait for all threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(1);
        }
    }

    return 0;
}