//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: cheerful
#include <stdio.h>
#include <pthread.h>

// Define the number of threads we want to create
#define NUM_THREADS 4 

// Define a simple data structure to pass arguments to our threads
typedef struct {
    int thread_id;
    char* message;
} ThreadArgs;

// This is the function that our threads will run
void* thread_function(void* args) {
    // Cast the void pointer to the ThreadArgs pointer we expect
    ThreadArgs* thread_args = (ThreadArgs*)args;
    printf("Thread %d: %s\n", thread_args->thread_id, thread_args->message);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];

    // Create the threads and specify their arguments
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].thread_id = i;
        thread_args[i].message = "Hello from thread!";
        int result = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_args[i]);
        if (result != 0) {
            printf("Thread creation failed: %d\n", result);
            return 1;
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed successfully!\n");

    return 0;
}