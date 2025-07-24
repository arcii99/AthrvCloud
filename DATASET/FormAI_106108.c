//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 3

void *thread_function(void *arg)
{
    for(int i=0; i<5; i++)
    {
        printf("Thread %d running\n", *(int*)arg);
        usleep(*(int*)arg * 1000000);
    }
    pthread_exit(NULL);
}

int main()
{
    int threadArgs[THREAD_COUNT] = {1, 2, 3};
    pthread_t threads[THREAD_COUNT];

    printf("Creating %d threads...\n", THREAD_COUNT);

    for(int i=0; i<THREAD_COUNT; i++)
    {
        int result = pthread_create(&threads[i], NULL, thread_function, &threadArgs[i]);
        if(result != 0)
        {
            printf("Error creating thread %d\n", i+1);
            exit(EXIT_FAILURE);
        }
    }

    for(int i=0; i<THREAD_COUNT; i++)
    {
        int result = pthread_join(threads[i], NULL);
        if(result != 0)
        {
            printf("Error joining thread %d\n", i+1);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads complete\n");

    return 0;
}