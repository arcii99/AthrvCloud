//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Romeo and Juliet
// Romeo and Juliet Thread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 2

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;

int shared_var = 0;

void *romeo(void *arg)
{
    // Romeo thread increments shared variable 10 times
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);
        printf("Romeo: My fair Juliet, let me increase our shared love!\n");
        shared_var++;
        printf("Romeo: Our love has increased to %d!\n", shared_var);
        pthread_mutex_unlock(&mutex);
        usleep(500000);
    }
    pthread_exit(NULL);
}

void *juliet(void *arg)
{
    // Juliet thread decrements shared variable 10 times
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);
        printf("Juliet: My dear Romeo, let me decrease our shared love!\n");
        shared_var--;
        printf("Juliet: Our love has decreased to %d!\n", shared_var);
        pthread_mutex_unlock(&mutex);
        usleep(500000);
    }
    pthread_exit(NULL);
}

int main()
{
    // Initialize mutex
    if (pthread_mutex_init(&mutex, NULL) != 0)
    {
        printf("Mutex initialization failed.\n");
        exit(1);
    }

    // Create threads
    printf("Romeo: Let us start our journey of love.\n");
    int rc;
    rc = pthread_create(&threads[0], NULL, romeo, NULL);
    if (rc)
    {
        printf("Error creating Romeo thread.\n");
        exit(1);
    }

    rc = pthread_create(&threads[1], NULL, juliet, NULL);
    if (rc)
    {
        printf("Error creating Juliet thread.\n");
        exit(1);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_join(threads[i], NULL);
        if (rc)
        {
            printf("Error joining thread %d.\n", i);
            exit(1);
        }
    }

    // Cleanup mutex
    pthread_mutex_destroy(&mutex);

    printf("Romeo: Our journey of love has ended.\n");

    return 0;
}