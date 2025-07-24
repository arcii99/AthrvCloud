//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: creative
// A creative implementation of a threading library in C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *arg);

int main()
{
    pthread_t thread_id[NUM_THREADS];

    int i, j;

    for(i = 0; i < NUM_THREADS; i++)
    {
        printf("Creating thread: %d\n", i);

        if(pthread_create(&thread_id[i], NULL, thread_function, &i) != 0)
        {
            printf("Error creating thread: %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for(j = 0; j < NUM_THREADS; j++)
    {
        if(pthread_join(thread_id[j], NULL) != 0)
        {
            printf("Error joining thread: %d\n", j);
            exit(EXIT_FAILURE);
        }

        printf("Thread %d joined successfully!\n", j);
    }

    return 0;
}

void *thread_function(void *arg)
{
    int thread_number = *(int *)arg;

    printf("Thread %d started!\n", thread_number);

    // Do some work here...

    printf("Thread %d finished!\n", thread_number);

    pthread_exit(NULL);
}