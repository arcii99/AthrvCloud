//FormAI DATASET v1.0 Category: Arithmetic ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 5

int sum = 0;
pthread_mutex_t mutex_sum;

void *sum_of_numbers(void *arg) {
    int id = *(int*)arg;
    int start = id * 100 + 1;
    int end = start + 99;
    int local_sum = 0;

    for (int i = start; i <= end; i++) {
        local_sum += i;
    }

    // Acquire lock on mutex_sum
    pthread_mutex_lock(&mutex_sum);
  
    // Update the global sum
    sum += local_sum;

    // Release lock on mutex_sum
    pthread_mutex_unlock(&mutex_sum);

    printf("Thread %d, local_sum: %d\n", id, local_sum);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    // Initialize mutex_sum
    pthread_mutex_init(&mutex_sum, NULL);

    // Create threads
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, sum_of_numbers, &thread_ids[i]) != 0) {
            perror("pthread_create error");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join error");
            exit(EXIT_FAILURE);
        }
    }

    // Destroy mutex_sum
    pthread_mutex_destroy(&mutex_sum);

    printf("Sum of numbers from 1 to 500: %d\n", sum);

    return 0;
}