//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 5
#define ARRAY_SIZE 100000

int shared_array[ARRAY_SIZE];

// Function to be executed by each thread
void *thread_func(void *arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d starting...\n", thread_id);

    // Each thread fills in its section of the shared_array
    int start_index = thread_id * (ARRAY_SIZE / THREAD_COUNT);
    int end_index = start_index + (ARRAY_SIZE / THREAD_COUNT);
    for (int i = start_index; i < end_index; i++) {
        shared_array[i] = i;
    }

    printf("Thread %d finished.\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    printf("Main thread starting...\n");

    pthread_t threads[THREAD_COUNT];
    int thread_ids[THREAD_COUNT];

    // Create threads and start executing thread_func on each one
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_func, &thread_ids[i])) {
            perror("Error creating thread");
            exit(1);
        }
    }

    // Wait for all threads to finish executing
    for (int i = 0; i < THREAD_COUNT; i++) {
        if (pthread_join(threads[i], NULL)) {
            perror("Error joining thread");
            exit(1);
        }
    }

    // Check that the shared_array was properly filled in by all threads
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (shared_array[i] != i) {
            printf("Error: shared_array[%d] = %d\n", i, shared_array[i]);
            exit(1);
        }
    }

    printf("Main thread finished.\n");
    return 0;
}