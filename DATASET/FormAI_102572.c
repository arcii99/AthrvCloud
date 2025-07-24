//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: creative
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_function(void *arg);

int main()
{
    pthread_t my_thread;
    int thread_arg = 42;

    if (pthread_create(&my_thread, NULL, thread_function, &thread_arg))
    {
        printf("Error creating thread!\n");
        exit(1);
    }

    printf("Created thread successfully!\n");

    pthread_join(my_thread, NULL);

    printf("Thread finished execution!\n");

    return 0;
}

void *thread_function(void *arg)
{
    int i;
    int *thread_arg = (int *)arg;

    for (i = 0; i < 10; i++)
    {
        printf("Thread %d running iteration %d with arg %d\n", (int)pthread_self(), i, *thread_arg);
    }

    return NULL;
}