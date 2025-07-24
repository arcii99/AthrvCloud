//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: relaxed
#include <pthread.h>
#include <stdio.h>

// this function will be executed by the threads
void* hello_thread(void* arg)
{
    printf("Hello, thread %ld!\n", (long) arg);
    pthread_exit(NULL);
}

int main()
{
    const int NUM_THREADS = 4;
    pthread_t threads[NUM_THREADS]; // array of threads

    // create the threads
    for (long i = 0; i < NUM_THREADS; i++)
    {
        int rc = pthread_create(&threads[i], NULL, hello_thread, (void*) i);
        if (rc)
        {
            printf("Error creating thread: %d\n", rc);
            return 1;
        }
    }

    // wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed.\n");

    return 0;
}