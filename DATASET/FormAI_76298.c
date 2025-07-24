//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 1000000

int array[ARRAY_SIZE];
pthread_mutex_t mutex_sum;

void fill_array() {
    srand(time(NULL));
    for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
}

void* calculate_sum(void* thread_id) {
    uint32_t id = *((uint32_t*)thread_id);
    int sum = 0;
    for(int i = id * (ARRAY_SIZE / NUM_THREADS); i < (id + 1) * (ARRAY_SIZE / NUM_THREADS); i++) {
        sum += array[i];
    }

    pthread_mutex_lock(&mutex_sum);
    int* total_sum = (int*)malloc(sizeof(int));
    *total_sum = sum;
    pthread_mutex_unlock(&mutex_sum);

    pthread_exit(total_sum);
}

int main() {
    fill_array();
    pthread_mutex_init(&mutex_sum, NULL);
    pthread_t threads[NUM_THREADS];
    uint32_t thread_ids[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_sum, (void*)&thread_ids[i]);
    }

    int total_sum = 0;
    for(int i = 0; i < NUM_THREADS; i++) {
        void* sum_ptr;
        pthread_join(threads[i], &sum_ptr);
        total_sum += *(int*)sum_ptr;
        free(sum_ptr);
    }

    pthread_mutex_destroy(&mutex_sum);
    printf("The sum of the array is %d\n", total_sum);
    return 0;
}