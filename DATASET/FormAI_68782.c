//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int main()
{
    pthread_t my_thread;
    int ret, thread_args = 10;

    ret = pthread_create(&my_thread, NULL, thread_function, (void *)thread_args);
    if (ret != 0)
    {
        printf("Error: pthread_create() failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Main thread\n");
    printf("Thread ID is: %lu\n", pthread_self());

    ret = pthread_join(my_thread, NULL);
    if (ret != 0)
    {
        printf("Error: pthread_join() failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Thread exited\n");

    return 0;
}

void *thread_function(void *arg)
{
    int i;
    int count = (int)arg;

    printf("Thread started\n");
    printf("Thread ID is: %lu\n", pthread_self());

    for (i = 0; i < count; i++)
    {
        printf("Thread count %d\n", i);
    }

    printf("Thread finished\n");

    pthread_exit(NULL);
}