//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *arg)
{
    int i;
    printf("Thread %d is running...\n", *(int *)arg);

    for (i = 0; i < 10; i++)
    {
        printf("Thread %d is counting %d...\n", *(int *)arg, i);
    }

    printf("Thread %d is done.\n", *(int *)arg);
    pthread_exit(NULL);
}

int main(void)
{
    int i;
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    printf("Creating %d threads...\n", NUM_THREADS);

    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_func, &thread_args[i]) != 0)
        {
            perror("pthread_create failed!");
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads created!\n");

    for (i = 0; i < NUM_THREADS; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("pthread_join failed!");
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads have finished!\n");
    return 0;
}