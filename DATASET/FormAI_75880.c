//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 1000000

int global_array[ARRAY_SIZE];

void *sum_thread(void *threadid){
    long tid;
    int start, end, sum = 0;
    tid = (long)threadid;
    start = tid * (ARRAY_SIZE / NUM_THREADS);
    end = start + (ARRAY_SIZE / NUM_THREADS);

    for(int i=start; i<end; i++){
        sum += global_array[i];
    }

    pthread_exit((void*) sum);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int thread_sums[NUM_THREADS];
    int final_sum = 0;

    // Initialize global_array with random numbers
    for(int i=0; i<ARRAY_SIZE; i++){
        global_array[i] = rand() % 1000;
    }

    // Create threads and sum up array in segments
    for(long i=0; i<NUM_THREADS; i++){
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, sum_thread, (void*) i);
    }

    // Join all threads and get their results
    for(int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], (void**)&thread_sums[i]);
    }

    // Add up all thread sums to get the final sum
    for(int i=0; i<NUM_THREADS; i++){
        final_sum += thread_sums[i];
    }

    printf("Final sum: %d\n", final_sum);

    return 0;
}