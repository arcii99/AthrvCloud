//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_SIZE 1000000

int array[MAX_SIZE];
int sum[MAX_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* threadSum(void* arg) {
    int thread_id = *((int*) arg);
    int start_index = thread_id * (MAX_SIZE / MAX_THREADS);
    int end_index = start_index + (MAX_SIZE / MAX_THREADS);
    int local_sum = 0;

    for (int i = start_index; i < end_index; i++) {
        local_sum += array[i];
    }

    pthread_mutex_lock(&mutex);
    sum[thread_id] = local_sum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    // Fill the array with random integers between 1 and 10
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        array[i] = rand() % 10 + 1;
    }

    // Create threads
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, threadSum, &thread_ids[i]) != 0) {
            printf("Failed to create thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Failed to join thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Compute the final sum
    int total_sum = 0;
    for (int i = 0; i < MAX_THREADS; i++) {
        total_sum += sum[i];
    }

    printf("The sum of the array is: %d\n", total_sum);

    return 0;
}