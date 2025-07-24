//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void *thread_function(void *arg);

int main()
{
    pthread_t threads[NUM_THREADS];

    int thread_args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0)
        {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            printf("Error joining thread %d\n", i);
            exit(1);
        }
    }

    return 0;
}

void *thread_function(void *arg)
{
    int thread_num = *(int *)arg;
    printf("Thread number %d\n", thread_num);
    return NULL;
}