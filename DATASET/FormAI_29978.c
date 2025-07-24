//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

// Struct for thread argument
typedef struct thread_arg
{
    int thread_id;
    int *data;
    int length;
} ThreadArg;

// Thread routine
void *thread_routine(void *arg)
{
    ThreadArg *thread_arg = (ThreadArg *)arg;
    int *data = thread_arg->data;
    int length = thread_arg->length;

    printf("Thread %d starting...\n", thread_arg->thread_id);

    // Perform some processing on data
    printf("Thread %d processing data: ", thread_arg->thread_id);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Thread %d exiting...\n", thread_arg->thread_id);

    pthread_exit(NULL);
}

int main()
{
    int data[100];
    int length = 100;

    // Initialize data array
    for (int i = 0; i < length; i++)
    {
        data[i] = i + 1;
    }

    // Create array of thread arguments
    ThreadArg thread_args[MAX_THREADS];

    // Create threads
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++)
    {
        thread_args[i].thread_id = i;
        thread_args[i].data = data + i * (length / MAX_THREADS);
        thread_args[i].length = length / MAX_THREADS;

        pthread_create(&threads[i], NULL, thread_routine, &thread_args[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished.\n");

    return 0;
}