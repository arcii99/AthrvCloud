//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAXELEMENTS 1000
#define MAXTHREADS 10

int arr[MAXELEMENTS];
int sum[MAXTHREADS];
int num_elements;
int num_threads;

void *thread_sum(void *arg) {
    int thread_id = *(int*)arg;
    int elements_per_thread = num_elements / num_threads;
    int start = thread_id * elements_per_thread;
    int end = (thread_id + 1) * elements_per_thread;

    for (int i = start; i < end; i++) {
        sum[thread_id] += arr[i];
    }

    return sum[thread_id];
}

int main() {
    // Initialize array with random integers
    srand(time(NULL));
    for (int i = 0; i < MAXELEMENTS; i++) {
        arr[i] = rand() % 100;
    }
    num_elements = MAXELEMENTS;

    // Get number of threads
    printf("Enter number of threads (max %d): ", MAXTHREADS);
    scanf("%d", &num_threads);
    if (num_threads > MAXTHREADS) {
        num_threads = MAXTHREADS;
    }

    // Create and join threads
    pthread_t threads[MAXTHREADS];
    int thread_ids[MAXTHREADS];
    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_sum, &thread_ids[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Add all thread sums to get final sum
    int total_sum = 0;
    for (int i = 0; i < num_threads; i++) {
        total_sum += sum[i];
    }

    printf("Total sum of array elements: %d\n", total_sum);

    return 0;
}