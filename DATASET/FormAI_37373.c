//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *arg)
{
    int thread_id = *(int *)arg;
    printf("Thread %d is now running...\n", thread_id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    int i;
    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0)
        {
            printf("Error creating thread %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            printf("Error joining thread %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads have completed!\n");
    return 0;
}