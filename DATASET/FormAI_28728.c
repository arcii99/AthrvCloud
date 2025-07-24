//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 10
#define ARRAY_SIZE 100000

typedef struct {
    int thread_num;
    int* array;
    int start_index;
    int end_index;
    int sum;
} ThreadData;

void* computeSum(void* thread_data) {
    ThreadData* data = (ThreadData*) thread_data;
    
    int i, local_sum = 0;
    for (i = data->start_index; i < data->end_index; i++) {
        local_sum += data->array[i];
    }
    data->sum = local_sum;
    
    printf("Thread %d computed sum = %d\n", data->thread_num, data->sum);
    
    pthread_exit(NULL);
}

int main() {
    int* array = (int*) malloc(ARRAY_SIZE * sizeof(int));
    if (array == NULL) {
        printf("Error allocating memory for array\n");
        return 1;
    }
    
    srand(time(NULL));
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
    
    pthread_t threads[NUM_THREADS];
    
    ThreadData thread_data[NUM_THREADS];
    int chunk_size = ARRAY_SIZE / NUM_THREADS;
    
    for (i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_num = i;
        thread_data[i].array = array;
        thread_data[i].start_index = i * chunk_size;
        thread_data[i].end_index = (i == (NUM_THREADS - 1)) ? ARRAY_SIZE : (i + 1) * chunk_size;
        
        int ret = pthread_create(&threads[i], NULL, computeSum, (void*) &thread_data[i]);
        if (ret) {
            printf("Error creating thread %d\n", i);
            return 1;
        }
    }
    
    int total_sum = 0;
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_sum += thread_data[i].sum;
    }
    
    printf("Total sum = %d\n", total_sum);
    
    free(array);
    
    return 0;
}