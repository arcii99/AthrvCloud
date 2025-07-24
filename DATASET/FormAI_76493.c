//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 100000

// struct to hold data for the thread
typedef struct {
    int *array;
    int start_index;
    int end_index;
    int sum;
} ThreadData;

// thread function to compute the sum of array elements
void *sum_array(void *arg) {
    ThreadData *data = (ThreadData*) arg;
    int i;
    for (i = data->start_index; i < data->end_index; i++) {
        data->sum += data->array[i];
    }
    pthread_exit(NULL);
}

int main() {
    int i;
    int array[ARRAY_SIZE];
    int sum = 0;
    pthread_t threads[4];
    ThreadData thread_data[4];

    // initialize array with random values
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10 + 1;
    }

    // create threads and assign work
    for (i = 0; i < 4; i++) {
        thread_data[i].array = array;
        thread_data[i].start_index = i * (ARRAY_SIZE / 4);
        thread_data[i].end_index = (i + 1) * (ARRAY_SIZE / 4);
        thread_data[i].sum = 0;
        pthread_create(&threads[i], NULL, sum_array, (void*) &thread_data[i]);
    }

    // wait for threads to finish
    for (i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
        sum += thread_data[i].sum;
    }

    // print out results
    printf("Array sum is %d\n", sum);
    return 0;
}