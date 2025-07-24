//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: minimalist
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_THREADS 10

void *thread_function(void *arg);

int main()
{
    pthread_t threads[MAX_THREADS];
    int thread_args[MAX_THREADS];
    int i;

    for (i = 0; i < MAX_THREADS; i++)
    {
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, (void *)&thread_args[i]) != 0)
        {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    for (i = 0; i < MAX_THREADS; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            printf("Error joining thread %d\n", i);
            exit(-1);
        }
    }

    return 0;
}

void *thread_function(void *arg)
{
    int thread_arg = *(int *)arg;
    printf("Thread %d started\n", thread_arg);
    sleep(1);
    printf("Thread %d ended\n", thread_arg);
    return NULL;
}