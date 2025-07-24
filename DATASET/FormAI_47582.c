//FormAI DATASET v1.0 Category: Data mining ; Style: multi-threaded
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREADS 10
#define MAX_DATA 100

int data[MAX_DATA]; // Our data array
int data_size; // The size of our data array

void* processData(void* arg) {
    int thread_id = *(int*)arg;
    int start_index = (data_size/MAX_THREADS) * thread_id;
    int end_index = (data_size/MAX_THREADS) * (thread_id + 1) - 1;
    
    printf("Thread %d processing data from index %d to %d\n", thread_id, start_index, end_index);
    
    int sum = 0;
    for (int i = start_index; i <= end_index; i++) {
        sum += data[i];
    }
    
    int* result = malloc(sizeof(int));
    *result = sum;
    pthread_exit(result);
}

int main() {
    // Initialize data array with random numbers
    srand(time(NULL)); // Seed the random number generator
    data_size = MAX_DATA;
    for(int i = 0; i < data_size; i++) {
        data[i] = rand() % 100;
    }
    
    // Initialize threads
    int num_threads = MAX_THREADS;
    pthread_t threads[num_threads];
    int thread_ids[num_threads];
    
    // Create threads
    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, processData, &thread_ids[i]);
    }
    
    // Wait for threads to finish and collect results
    int total_sum = 0;
    for (int i = 0; i < num_threads; i++) {
        int* result;
        pthread_join(threads[i], (void**)&result);
        total_sum += *result;
        free(result);
    }
    
    printf("Total sum of data: %d\n", total_sum);
    
    pthread_exit(NULL);
    return 0;
}