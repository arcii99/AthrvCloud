//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: retro
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of threads that can be created
#define MAX_THREADS 10

// Define the number of iterations for each thread
#define ITERATIONS 10

// Define the struct to be passed to the thread
typedef struct {
    int id;
    char message[50];
} thread_args_t;

// Define the function to be executed by the thread
void* thread_func(void* arg) {
    thread_args_t* args = arg;
    int i;

    for (i = 0; i < ITERATIONS; i++) {
        printf("Thread %d: %s\n", args->id, args->message);
        sleep(1);
    }

    pthread_exit(NULL);
}

// Define the main function
int main(void) {
    pthread_t threads[MAX_THREADS];
    thread_args_t args[MAX_THREADS];
    int i;

    // Create the threads with their respective arguments
    for (i = 0; i < MAX_THREADS; i++) {
        args[i].id = i;
        sprintf(args[i].message, "Iteration %d", i);
        pthread_create(&threads[i], NULL, thread_func, &args[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}