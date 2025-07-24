//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_function(void *thread_arg)
{
    int tid = *((int *)thread_arg);
    printf("Thread %d starting...\n", tid);
    sleep(1 + tid);
    printf("Thread %d done.\n", tid);
    free(thread_arg);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int *thread_args[NUM_THREADS];
    int i;

    printf("Creating %d threads...\n", NUM_THREADS);
    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = malloc(sizeof(int));
        *thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void *)thread_args[i]);
    }

    printf("Waiting for threads to finish...\n");
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads done.\n");
    return 0;
}