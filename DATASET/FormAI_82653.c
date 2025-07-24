//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define THREADS_COUNT 4
#define TOTAL_ITERATIONS 1000000000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *threadFunction(void *param) {
    int thread_id = *(int*)param;
    long int sum = 0;

    for (int i = thread_id; i < TOTAL_ITERATIONS; i += THREADS_COUNT) {
        sum += i;
    }

    pthread_mutex_lock(&mutex);
    *(long int*)param = sum;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS_COUNT];
    long int sums[THREADS_COUNT];
    int thread_ids[THREADS_COUNT];

    // Initialize thread IDs and sums
    for (int i = 0; i < THREADS_COUNT; i++) {
        thread_ids[i] = i;
        sums[i] = 0;
    }

    // Start timer
    clock_t start_time = clock();

    // Create threads and run threadFunction
    for (int i = 0; i < THREADS_COUNT; i++) {
        pthread_create(&threads[i], NULL, threadFunction, &sums[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < THREADS_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculate total sum
    long int total_sum = 0;
    for (int i = 0; i < THREADS_COUNT; i++) {
        total_sum += sums[i];
    }

    // Calculate execution time and print results
    double execution_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    printf("Total: %ld\n", total_sum);
    printf("Execution time: %f\n", execution_time);
    return 0;
}