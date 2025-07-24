//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a struct to pass arguments to the thread
typedef struct{
    int id;
    int num_iterations;
} thread_args;

// Define the thread function. It will print the thread id and sleep for a second
void* thread_func(void* args)
{
    thread_args* t_args = (thread_args*) args;
    for(int i=0; i < t_args->num_iterations; i++)
    {
        printf("Thread %d: iteration %d\n", t_args->id, i);
        sleep(1);
    }
    return NULL;
}

int main()
{
    int NUM_THREADS = 5;
    int NUM_ITERATIONS = 3;

    pthread_t threads[NUM_THREADS];
    thread_args args[NUM_THREADS];

    // Create the threads
    for(int i=0; i < NUM_THREADS; i++)
    {
        args[i].id = i;
        args[i].num_iterations = NUM_ITERATIONS;
        pthread_create(&threads[i], NULL, thread_func, (void*) &args[i]);
    }

    // Wait for the threads to finish
    for(int i=0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished\n");

    return 0;
}