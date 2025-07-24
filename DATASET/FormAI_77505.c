//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_message(void *thread_id)
{
    int id = *(int*)thread_id;
    printf("Thread #%d: Hello, World!\n", id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i, rc;

    for (i = 0; i < NUM_THREADS; i++)
    {
        printf("Creating thread #%d\n", i);
        thread_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, print_message, &thread_ids[i]);

        if (rc)
        {
            printf("Error creating thread #%d\n", i);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Thread #%d has completed.\n", i);
    }

    pthread_exit(NULL);
}