//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define ARRAY_SIZE 10000000

int global_array[ARRAY_SIZE];

void *thread_function(void *thread_arg) {
    int id = *(int *)thread_arg;
    int start_index = id * (ARRAY_SIZE / NUM_THREADS);
    int end_index = (id + 1) * (ARRAY_SIZE / NUM_THREADS);

    for (int i = start_index; i < end_index; i++) {
        global_array[i] = id;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Global array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", global_array[i]);
    }
    printf("\n");

    return 0;
}