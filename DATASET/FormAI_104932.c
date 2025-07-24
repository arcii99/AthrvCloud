//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;

int counter = 0;

void *thread_func(void *thread_id) {
    int tid = *((int *) thread_id);
    int local_counter = 0;

    while (local_counter < 10) {
        pthread_mutex_lock(&mutex);
        counter++;
        printf("Thread %d: Counter value is %d\n", tid, counter);
        pthread_mutex_unlock(&mutex);
        local_counter++;

        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    int i, ids[NUM_THREADS];

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void *) &ids[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}