//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 100000000

int global_array[ARRAY_SIZE];

void *math_operation(void *thread_id) {
    long tid;
    tid = (long)thread_id;
    int i;
    int start_index = ARRAY_SIZE / NUM_THREADS * tid;
    int end_index = start_index + ARRAY_SIZE / NUM_THREADS;
    for (i = start_index; i < end_index; i++) {
        global_array[i] = global_array[i] * 2 + 5;
    }
    printf("Thread %ld completed math operation on %d elements\n", tid, end_index-start_index);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        global_array[i] = i;
    }
    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        pthread_create(&threads[i], NULL, math_operation, (void *)i);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Math Operation Completed\n");
    return 0;
}