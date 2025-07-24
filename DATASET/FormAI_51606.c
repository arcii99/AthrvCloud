//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define THREAD_COUNT 10
#define ARRAY_SIZE 1000000

int array[ARRAY_SIZE];

void *thread_func(void *thread_id){
    long tid = (long) thread_id;
    int start = tid * (ARRAY_SIZE / THREAD_COUNT);
    int end = start + (ARRAY_SIZE / THREAD_COUNT);

    // Sum the values in this thread's section of the array
    int sum = 0;
    for(int i = start; i < end; i++){
        sum += array[i];
    }
    printf("Thread %ld sum: %d\n", tid, sum);

    pthread_exit(NULL);
}

int main(){
    srand(time(NULL));
    clock_t start, end;
    double cpu_time_used;

    // Initialize array with random values
    for(int i = 0; i < ARRAY_SIZE; i++){
        array[i] = rand() % 100;
    }

    // Create array of threads
    pthread_t threads[THREAD_COUNT];

    start = clock();

    // Start each thread and pass thread_id as argument
    for(long i = 0; i < THREAD_COUNT; i++){
        pthread_create(&threads[i], NULL, thread_func, (void *) i);
    }

    // Wait for all threads to finish
    for(int i = 0; i < THREAD_COUNT; i++){
        pthread_join(threads[i], NULL);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time: %f\n", cpu_time_used);

    pthread_exit(NULL);
}