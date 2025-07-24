//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAXTHREADS 5

void *task(void *arg)
{
    int tid = *((int *) arg);
    printf("Thread %d executing...\n", tid);
    pthread_exit(NULL);
}

int main()
{
    int i, error;
    pthread_t thread_id[MAXTHREADS];
    int tid[MAXTHREADS];
    for(i=0; i<MAXTHREADS; i++)
    {
        tid[i] = i+1;
        error = pthread_create(&thread_id[i], NULL, task, &tid[i]);
        if(error != 0)
        {
            printf("Error: Failed to create thread %d\n", tid[i]);
            exit(EXIT_FAILURE);
        }
    }
    for(i=0; i<MAXTHREADS; i++)
    {
        error = pthread_join(thread_id[i], NULL);
        if(error != 0)
        {
            printf("Error: Failed to join thread %d\n", tid[i]);
            exit(EXIT_FAILURE);
        }
        printf("Thread %d completed.\n", tid[i]);
    }
    return 0;
}