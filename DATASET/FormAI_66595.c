//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

// Struct to hold thread information
typedef struct thread_data {
    int thread_id;
    int thread_num;
} ThreadData;

// Function to be executed by each thread
void *execute_thread(void *thread_data) {
    ThreadData *data = (ThreadData *) thread_data;
    printf("Hello from thread #%d running function #%d!\n", data->thread_id, data->thread_num);
    printf("Thread #%d exiting...\n", data->thread_id);
    pthread_exit(NULL);
}

// Helper function to initialize threads
void init_threads(pthread_t *threads, ThreadData *thread_data_array) {
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        thread_data_array[i].thread_id = i;
        thread_data_array[i].thread_num = rand() % 10 + 1; // Random function to determine which function the thread will run
        printf("Creating thread #%d to execute function #%d...\n", i, thread_data_array[i].thread_num);
        pthread_create(&threads[i], NULL, execute_thread, (void *) &thread_data_array[i]);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data_array[NUM_THREADS];
    int i;

    printf("Starting %d threads...\n", NUM_THREADS);
    init_threads(threads, thread_data_array);

    // Wait for all threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Exiting program...\n");
    pthread_exit(NULL);
}