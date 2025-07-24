//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 1000000

int shared_data[ARRAY_SIZE];

void *thread_function(void *thread_id) {
    int id = *(int*)thread_id;
    int i;

    for (i = id; i < ARRAY_SIZE; i += NUM_THREADS) {
        shared_data[i] = i * 2;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    int max = shared_data[0];
    for (i = 1; i < ARRAY_SIZE; i++) {
        if (shared_data[i] > max) {
            max = shared_data[i];
        }
    }

    printf("Maximum value in the array: %d\n", max);

    return 0;
}