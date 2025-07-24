//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *threadFunction(void *arg);

int main()
{
    pthread_t threads[NUM_THREADS];
    int threadArgs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        threadArgs[i] = i;
        if (pthread_create(&threads[i], NULL, threadFunction, &threadArgs[i]) != 0)
        {
            printf("Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            printf("Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads completed successfully\n");
    exit(EXIT_SUCCESS);
}

void *threadFunction(void *arg)
{
    int threadNum = *(int *)arg;
    printf("Thread %d starting\n", threadNum);
    sleep(1);
    printf("Thread %d ending\n", threadNum);
    pthread_exit(NULL);
}