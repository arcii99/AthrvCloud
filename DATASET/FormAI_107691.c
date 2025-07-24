//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// function to be executed by threads
void *threadFunction(void *threadID)
{
    int* id = (int*) threadID;
    printf("Thread %d is running.\n", *id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
    {
        threadIDs[i] = i;
        int status = pthread_create(&threads[i], NULL, threadFunction, &threadIDs[i]);

        if (status != 0)
        {
            printf("Error: unable to create thread, error code: %d\n", status);
            exit(-1);
        }
    }

    // wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished.\n");
    return 0;
}