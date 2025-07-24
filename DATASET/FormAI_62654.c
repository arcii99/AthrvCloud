//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multi-threaded
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 1000000
#define BLOCK_SIZE ARRAY_SIZE / NUM_THREADS

int array[ARRAY_SIZE];
int result[NUM_THREADS] = {0};

void *sum(void *args) {
    int thread_num = *(int *)args;
    int start = thread_num * BLOCK_SIZE;
    int end = start + BLOCK_SIZE;
    for (int i = start; i < end; i++) {
        result[thread_num] += array[i];
    }
    return NULL;
}

int main() {
    srandom(0);
    int sum_serial = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = random() % 1000;
        sum_serial += array[i];
    }

    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, sum, (void *)&thread_args[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    int sum_parallel = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        sum_parallel += result[i];
    }

    printf("Serial sum:   %d\n", sum_serial);
    printf("Parallel sum: %d\n", sum_parallel);
    if (sum_serial == sum_parallel) {
        printf("Results match\n");
    } else {
        printf("Results do not match\n");
    }

    return 0;
}