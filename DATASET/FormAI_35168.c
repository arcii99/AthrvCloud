//FormAI DATASET v1.0 Category: Benchmarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 1000000

int array[ARRAY_SIZE];

void *minimum(void *arg) {
    int tid = (int)arg;
    int min_val = array[(ARRAY_SIZE/NUM_THREADS) * tid];
    int i;
    for(i = (ARRAY_SIZE/NUM_THREADS) * tid + 1; i < (ARRAY_SIZE/NUM_THREADS) * (tid + 1); i++) {
        if(array[i] < min_val) {
            min_val = array[i];
        }
    }
    printf("Thread %d computed the minimum value: %d\n", tid, min_val);
    pthread_exit(NULL);
}

void *maximum(void *arg) {
    int tid = (int)arg;
    int max_val = array[(ARRAY_SIZE/NUM_THREADS) * tid];
    int i;
    for(i = (ARRAY_SIZE/NUM_THREADS) * tid + 1; i < (ARRAY_SIZE/NUM_THREADS) * (tid + 1); i++) {
        if(array[i] > max_val) {
            max_val = array[i];
        }
    }
    printf("Thread %d computed the maximum value: %d\n", tid, max_val);
    pthread_exit(NULL);
}

void *average(void *arg) {
    int tid = (int)arg;
    int total_sum = 0;
    int i;
    for(i = (ARRAY_SIZE/NUM_THREADS) * tid; i < (ARRAY_SIZE/NUM_THREADS) * (tid + 1); i++) {
        total_sum += array[i];
    }
    printf("Thread %d computed the average value: %f\n", tid, (float)total_sum / (ARRAY_SIZE/NUM_THREADS));
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    int i;
    for(i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    for(i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, minimum, (void *)thread_args[i]);
        pthread_create(&threads[i], NULL, maximum, (void *)thread_args[i]);
        pthread_create(&threads[i], NULL, average, (void *)thread_args[i]);
    }
    for(i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}