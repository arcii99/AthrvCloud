//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: systematic
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id)
{
    long id = (long)thread_id;
    printf("Hello from thread %ld\n", id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];

    for (long i = 0; i < NUM_THREADS; i++)
    {
        printf("Creating thread %ld\n", i);
        int rc = pthread_create(&threads[i], NULL, print_hello, (void *)i);
        if (rc)
        {
            printf("Error creating thread %ld\n", i);
            return -1;
        }
    }

    for (long i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}