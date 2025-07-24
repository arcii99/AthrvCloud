//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: creative
/* Welcome to the Multithreading World! */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Define the number of threads to be used
#define NUM_THREADS 5

// Create a struct to hold the thread arguments
struct thread_args {
    int thread_id;
    char* message;
};

// Define the thread function
void* thread_function(void* args) {
    // Cast the void* args to the correct type
    struct thread_args* t_args = (struct thread_args*) args;

    // Print the thread ID and message
    printf("Thread ID: %d\n", t_args->thread_id);
    printf("Message: %s\n", t_args->message);

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Create an array of threads
    pthread_t threads[NUM_THREADS];

    // Create an array of thread arguments
    struct thread_args thread_args_arr[NUM_THREADS];

    // Define the messages to be passed to each thread
    char* messages[NUM_THREADS] = {
        "Hello from Thread 1!",
        "Hello from Thread 2!",
        "Hello from Thread 3!",
        "Hello from Thread 4!",
        "Hello from Thread 5!"
    };

    // Create each thread and pass the thread arguments
    for (int i = 0; i < NUM_THREADS; i++) {
        // Set the thread ID and message
        thread_args_arr[i].thread_id = i;
        thread_args_arr[i].message = messages[i];

        // Create the thread
        int rc = pthread_create(&threads[i], NULL, thread_function, (void*) &thread_args_arr[i]);

        // Check for errors
        if (rc) {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for each thread to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Exit the program
    return 0;
}