//FormAI DATASET v1.0 Category: Computer Biology ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10 // Maximum number of threads
#define MAX_DATA 1000 // Maximum number of data points

struct thread_data_t {
    int data_array[MAX_DATA];
    int sum;
    int tid;
};

void *find_sum(void *arg) {
    struct thread_data_t *data;
    data = (struct thread_data_t *) arg;
    int i;
    for (i=0; i<MAX_DATA; i++) {
        data->sum += data->data_array[i];
    }
    printf("Thread %d computed sum %d\n", data->tid, data->sum);
    pthread_exit(NULL);
}

int main() {
    int i, j, status;
    pthread_t threads[MAX_THREADS];
    struct thread_data_t thread_data[MAX_THREADS];

    // Generate some random data points
    for (i=0; i<MAX_DATA; i++) {
        thread_data[0].data_array[i] = rand() % 100;
    }

    // Create threads to compute the sum of different portions of the data_array
    int partition_size = MAX_DATA / MAX_THREADS;
    for (i=0; i<MAX_THREADS; i++) {
        thread_data[i].tid = i;
        thread_data[i].sum = 0;
        for (j=0; j<partition_size; j++) {
            thread_data[i].data_array[j] = thread_data[0].data_array[i*partition_size + j];
        }
        if (i == MAX_THREADS - 1) {
            for (j=i*partition_size; j<MAX_DATA; j++) {
                thread_data[i].data_array[j-i*partition_size] = thread_data[0].data_array[j];
            }
        }
        status = pthread_create(&threads[i], NULL, find_sum, (void *)&thread_data[i]);
        if (status) {
            printf("ERROR: return code from pthread_create() is %d\n", status);
            exit(-1);
        }
    }

    // Wait for threads to finish and compute the final sum
    int final_sum = 0;
    for (i=0; i<MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
        final_sum += thread_data[i].sum;
    }
    printf("The final sum is %d\n", final_sum);

    pthread_exit(NULL);
}