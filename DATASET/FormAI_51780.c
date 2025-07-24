//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: decentralized
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_message(void *ptr);

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = i;
        printf("Creating thread %d\n", i);
        pthread_create(&threads[i], NULL, print_message, &thread_args[i]);
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Thread %d has finished executing\n", i);
    }

    return 0;
}

void *print_message(void *ptr)
{
    int thread_arg = *(int *)ptr;
    printf("Thread %d is executing\n", thread_arg);

    for (int i = 0; i < 10; i++)
    {
        printf("Hello world from thread %d, iteration %d\n", thread_arg, i);
        sleep(1);
    }

    pthread_exit(NULL);
}