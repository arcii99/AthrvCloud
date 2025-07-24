//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4

typedef struct {
    int *array;
    int size;
    int start_index;
    int end_index;
    int *result;
} thread_data_t;

void *find_max(void *thread_data)
{
    thread_data_t *data = (thread_data_t *)thread_data;
    int max = data->array[data->start_index];
    for (int i = data->start_index + 1; i <= data->end_index; i++) {
        if (data->array[i] > max) {
            max = data->array[i];
        }
    }
    *(data->result) = max;
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];
    int array[1000];
    int result[NUM_THREADS];
    int max = 0;

    // populate array with random values
    for (int i = 0; i < 1000; i++) {
        array[i] = rand() % 100;
    }
    
    // create threads and split work amongst them
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].array = array;
        thread_data[i].size = 1000;
        thread_data[i].start_index = i * 250;
        thread_data[i].end_index = (i + 1) * 250 - 1;
        thread_data[i].result = &(result[i]);
        pthread_create(&(threads[i]), NULL, find_max, &(thread_data[i]));
    }

    // wait for threads to finish and calculate overall max
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        if (result[i] > max) {
            max = result[i];
        }
    }

    printf("The max value in the array is %d\n", max);

    return 0;
}