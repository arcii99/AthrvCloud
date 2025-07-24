//FormAI DATASET v1.0 Category: Scientific ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 100000

int array[ARRAY_SIZE];
int sum[NUM_THREADS];

void *sum_array(void *arg) {
    int thread_id = *(int *)arg;
    int start = thread_id * (ARRAY_SIZE / NUM_THREADS);
    int end = (thread_id + 1) * (ARRAY_SIZE / NUM_THREADS);

    for (int i = start; i < end; i++) {
        sum[thread_id] += array[i];
    }

    return NULL;
}

int main() {
    // Populate array with random numbers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Create threads to sum a portion of the array
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i;
        pthread_create(&threads[i], NULL, sum_array, thread_id);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Combine thread sums to get final result
    int total_sum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        total_sum += sum[i];
    }

    printf("Total sum: %d\n", total_sum);

    return 0;
}