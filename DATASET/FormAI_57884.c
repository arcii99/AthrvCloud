//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 10000000
#define CHUNK_SIZE ARRAY_SIZE/NUM_THREADS

int array[ARRAY_SIZE];
int result[NUM_THREADS];
pthread_mutex_t lock;

void *worker(void *arg) {
    int *thread_id = (int*)arg;
    int start = *thread_id * CHUNK_SIZE;
    int end = start + CHUNK_SIZE;
    int sum = 0;

    for(int i = start; i < end; i++) {
        sum += array[i];
    }

    pthread_mutex_lock(&lock);
    result[*thread_id] = sum;
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    // Initialize the array with random values
    for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);

    // Create threads
    for(int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, worker, &thread_ids[i]);
    }

    // Join threads
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Sum up the results from all threads
    int total = 0;
    for(int i = 0; i < NUM_THREADS; i++) {
        total += result[i];
    }

    printf("The total sum is: %d\n", total);

    pthread_mutex_destroy(&lock);

    return 0;
}