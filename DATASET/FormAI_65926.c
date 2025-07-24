//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the error buffer size
#define ERROR_BUFFER_SIZE 128

// Define the number of threads to run
#define NUM_THREADS 5

// Define a struct to hold thread arguments
typedef struct {
    int thread_id;
} ThreadArgs;

// Define a global variable to track errors
volatile char error[ERROR_BUFFER_SIZE];

// Define a function to handle errors
void handle_error(const char* message) {
    snprintf(error, ERROR_BUFFER_SIZE, "Error: %s", message);
    fprintf(stderr, "%s\n", error);
    exit(1);
}

// Define a thread function to simulate work
void* do_work(void* args) {
    ThreadArgs* thread_args = (ThreadArgs*) args;
    printf("Thread %d starting work...\n", thread_args->thread_id);
    // Simulate some work
    int i;
    for (i = 0; i < 100000000; i++) {}
    // Simulate an error
    if (thread_args->thread_id == 3) {
        handle_error("Thread 3 encountered an error");
    }
    printf("Thread %d finished work.\n", thread_args->thread_id);
    return NULL;
}

int main() {
    // Initialize thread arguments
    ThreadArgs args[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        args[i].thread_id = i;
    }
    // Initialize array of threads
    pthread_t threads[NUM_THREADS];
    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, do_work, (void*) &args[i]);
        if (rc != 0) {
            handle_error("pthread_create failed");
        }
    }
    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_join(threads[i], NULL);
        if (rc != 0) {
            handle_error("pthread_join failed");
        }
    }
    printf("All threads finished successfully.\n");
    return 0;
}