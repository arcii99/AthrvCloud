//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 6

int current_probability = 0;
pthread_mutex_t probability_mutex = PTHREAD_MUTEX_INITIALIZER;

void* calculate_probability(void* arg) {
    int thread_id = *(int*)arg;
    int max_iterations = 1000000 / THREAD_COUNT;
    int i;

    for (i = 0; i < max_iterations; i++) {
        int change = rand() % 11 - 5;
        pthread_mutex_lock(&probability_mutex);
        current_probability += change;
        pthread_mutex_unlock(&probability_mutex);
    }

    printf("Thread %d finished\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    int thread_ids[THREAD_COUNT];
    pthread_t threads[THREAD_COUNT];
    int i;

    for (i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, calculate_probability, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < THREAD_COUNT; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }

    printf("Final probability: %d%%\n", current_probability);
    pthread_mutex_destroy(&probability_mutex);

    return 0;
}