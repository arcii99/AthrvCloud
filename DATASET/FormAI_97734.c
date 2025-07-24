//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    printf("Thread %d is starting...\n", thread_id);
    sleep(5);
    printf("Thread %d is done.\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i, rc;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
        if (rc) {
            printf("Error creating thread %d, return code: %d\n", i, rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error joining thread %d, return code: %d\n", i, rc);
            exit(-1);
        }
    }

    printf("All threads completed successfully.\n");

    return 0;
}