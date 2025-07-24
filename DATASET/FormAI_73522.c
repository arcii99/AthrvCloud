//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 4
#define MAX_DATA_SIZE 1000000

struct ThreadData {
    int *data;
    int start_index;
    int end_index;
    double *result;
};

void *computeSum(void *threadData){
    struct ThreadData *data = (struct ThreadData*) threadData;
    double sum = 0;
    for (int i=data->start_index; i<data->end_index; i++){
        sum += data->data[i];
    }
    *(data->result) += sum;
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    int data[MAX_DATA_SIZE];
    for (int i=0; i<MAX_DATA_SIZE; i++){
        data[i] = rand() % 100 + 1;
    }

    double sum = 0;
    pthread_t threads[MAX_THREADS];
    struct ThreadData threadData[MAX_THREADS];
    int chunk_size = MAX_DATA_SIZE / MAX_THREADS;
    int remainder = MAX_DATA_SIZE % MAX_THREADS;
    int start_index = 0;

    for (int i=0; i<MAX_THREADS; i++){
        threadData[i].data = data;
        threadData[i].start_index = start_index;

        if (remainder > 0){
            threadData[i].end_index = start_index + chunk_size + 1;
            remainder--;
        } else {
            threadData[i].end_index = start_index + chunk_size;
        }

        start_index = threadData[i].end_index;
        threadData[i].result = &sum;

        pthread_create(&threads[i], NULL, computeSum, (void *)&threadData[i]);
    }

    for (int i=0; i<MAX_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Sum of data: %.2f\n", sum);

    return 0;
}