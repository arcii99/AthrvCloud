//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *PrintHello(void *tid)
{
    int thread_id = *(int *)tid;
    printf("Hello from thread %d\n", thread_id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int t;

    for (t = 0; t < NUM_THREADS; t++)
    {
        thread_args[t] = t;
        printf("Creating thread %d\n", t);
        pthread_create(&threads[t], NULL, PrintHello, (void *)&thread_args[t]);
    }

    for (t = 0; t < NUM_THREADS; t++)
    {
        pthread_join(threads[t], NULL);
        printf("Thread %d has finished\n", t);
    }

    pthread_exit(NULL);
    return 0;
}