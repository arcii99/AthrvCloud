//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: real-life
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5 // Number of threads to be created

void *thread_function(void *arg)
{
    long thread_id = (long)arg; // Retrieve the thread ID
    printf("Thread %ld is running\n", thread_id);
    pthread_exit(NULL); // Terminate the thread
}

int main()
{
    pthread_t threads[NUM_THREADS]; // An array of thread identifiers
    int rc, i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        printf("Creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, thread_function, (void *)(long)i);
        if (rc) // Check for errors in thread creation
        {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL); // Wait for every thread to finish
        printf("Thread %d has finished\n", i);
    }

    pthread_exit(NULL); // Terminate the main thread
}