//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 5
#define ARRAY_SIZE 100000

int array[ARRAY_SIZE];

struct thread_data {
    int thread_id;
    int sum;
};

void* sum_array(void* threadarg) {
    struct thread_data* my_data;
    my_data = (struct thread_data*) threadarg;

    int start = my_data->thread_id * (ARRAY_SIZE / NUM_THREADS);
    int end = (my_data->thread_id + 1) * (ARRAY_SIZE / NUM_THREADS);
    my_data->sum = 0;

    for (int i = start; i < end; i++) {
        my_data->sum += array[i];
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct thread_data thread_data_array[NUM_THREADS];

    srand(time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_array[i].thread_id = i;
        thread_data_array[i].sum = 0;
        pthread_create(&threads[i], NULL, sum_array, (void*) &thread_data_array[i]);
    }

    int total_sum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_sum += thread_data_array[i].sum;
    }

    printf("Total sum: %d\n", total_sum);

    pthread_exit(NULL);
}