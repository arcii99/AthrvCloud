//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: scalable
// This program showcases a scalable implementation of C Threading Library

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 10

void *thread_function(void *arg)
{
    int thread_id = *(int*)arg;
    printf("Hello from thread %d\n", thread_id);
    sleep(1);
    printf("Thread %d is exiting\n", thread_id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads and pass thread ID as argument
    for(int i = 0; i < NUM_THREADS; i++)
    {
        printf("Creating thread %d\n", i);
        thread_ids[i] = i;
        int result = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        if(result)
        {
            fprintf(stderr, "Error creating thread %d: %d\n", i, result);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for(int i = 0; i < NUM_THREADS; i++)
    {
        int result = pthread_join(threads[i], NULL);
        if(result)
        {
            fprintf(stderr, "Error joining thread %d: %d\n", i, result);
            exit(-1);
        }
    }

    printf("Main thread exiting\n");
    pthread_exit(NULL);
}