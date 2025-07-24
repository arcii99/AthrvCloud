//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_function(void *arg)
{
    int thread_num = *(int*)arg;
    printf("Thread %d is starting...\n", thread_num);

    // Do some work
    for (int i = 0; i < 1000000; i++) {}

    printf("Thread %d is finishing...\n", thread_num);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    // Initialize thread arguments
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_args[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished.\n");

    return 0;
}