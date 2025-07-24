//FormAI DATASET v1.0 Category: Educational ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 3

void *thread_func(void *arg);

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        printf("Creating thread %ld\n", i);
        rc = pthread_create(&threads[i], NULL, thread_func, (void *) i);
        if (rc)
        {
            printf("Error creating thread %ld: %d\n", i, rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_join(threads[i], NULL);
        if (rc)
        {
            printf("Error joining thread %ld: %d\n", i, rc);
            exit(-1);
        }
        printf("Joined thread %ld\n", i);
    }

    return 0;
}

void *thread_func(void *arg)
{
    long thread_id = (long) arg;
    printf("Thread %ld starting\n", thread_id);
    sleep(thread_id + 1);
    printf("Thread %ld done\n", thread_id);
    pthread_exit(NULL);
}