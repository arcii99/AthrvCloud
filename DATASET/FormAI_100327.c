//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *thread_id) {
    int id = *((int *) thread_id);
    printf("Thread %d is starting.\n", id);
    sleep(1);
    printf("Thread %d is ending.\n", id);
    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        int ret = pthread_create(&threads[i], NULL, thread_func, (void *) &thread_ids[i]);
        if (ret) {
            printf("Error: pthread_create() failed\n");
            exit(EXIT_FAILURE);
        }
        printf("Created thread %d with ID %lu.\n", i, threads[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        int ret = pthread_join(threads[i], NULL);
        if (ret) {
            printf("Error: pthread_join() failed\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("Finished all threads.\n");
    return 0;
}