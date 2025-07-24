//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

void* thread_function(void* thread_arg)
{
    int tid;
    tid = *((int*) thread_arg);
    printf("Thread %d is starting\n", tid);
    sleep(1);
    printf("Thread %d is done\n", tid);
    return NULL;
}

int main(void)
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int rc, i;

    /* create all threads */
    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = i;
        printf("Creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    /* wait for all threads to complete */
    for (i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_join(threads[i], NULL);
        printf("Thread %d with thread_id %ld has completed\n", i, threads[i]);
        if (rc)
        {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    return 0;
}