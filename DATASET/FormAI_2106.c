//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 1000000

int array[ARRAY_SIZE];

void *sum_array(void *thread_id) {
    int tid = *(int*)thread_id;
    int start_index = tid * (ARRAY_SIZE / NUM_THREADS);
    int end_index = (tid + 1) * (ARRAY_SIZE / NUM_THREADS);
    int i;
    int thread_sum = 0;
    for (i=start_index; i<end_index; i++) {
        thread_sum += array[i];
    }
    return (void*)thread_sum;
}

int main() {
    int i;
    int total = 0;
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    srand(time(NULL));
    for (i=0; i<ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    for (i=0; i<NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, sum_array, (void*)&thread_ids[i]);
    }

    for (i=0; i<NUM_THREADS; i++) {
        int thread_sum;
        pthread_join(threads[i], (void**)&thread_sum);
        total += thread_sum;
    }

    printf("Total sum: %d\n", total);
    return 0;
}