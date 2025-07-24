//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *thread_id) {
    int tid = *(int*)thread_id;
    printf("Thread %d is running!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        int status = pthread_create(&threads[i], NULL, thread_func, (void*)&thread_ids[i]);
        if (status != 0) {
            fprintf(stderr, "Error creating thread %d: return code %d\n", i, status);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        int status = pthread_join(threads[i], NULL);
        if (status != 0) {
            fprintf(stderr, "Error joining thread %d: return code %d\n", i, status);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads have completed!\n");
    pthread_exit(NULL);
    return 0;
}