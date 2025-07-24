//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 50

// Define the mutex variables
pthread_mutex_t mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_3 = PTHREAD_MUTEX_INITIALIZER;

// Define the thread functions
void *thread_1_function(void *arg);
void *thread_2_function(void *arg);
void *thread_3_function(void *arg);

int main()
{
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    // Create thread 1
    thread_ids[0] = 1;
    pthread_create(&threads[0], NULL, thread_1_function, (void *)&thread_ids[0]);

    // Create thread 2
    thread_ids[1] = 2;
    pthread_create(&threads[1], NULL, thread_2_function, (void *)&thread_ids[1]);

    // Create thread 3
    thread_ids[2] = 3;
    pthread_create(&threads[2], NULL, thread_3_function, (void *)&thread_ids[2]);

    // Wait for all threads to complete
    for (int i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutexes
    pthread_mutex_destroy(&mutex_1);
    pthread_mutex_destroy(&mutex_2);
    pthread_mutex_destroy(&mutex_3);

    return 0;
}

void *thread_1_function(void *arg)
{
    int thread_id = *(int *)arg;
    int i;

    // Acquire mutex_1
    pthread_mutex_lock(&mutex_1);

    for (i = 0; i < 1000000; i++)
    {
        // Acquire mutex_2
        pthread_mutex_lock(&mutex_2);

        // Random code block
        printf("Thread %d executing\n", thread_id);
        fflush(stdout);
        usleep(random() % 1000000);

        // Release mutex_2
        pthread_mutex_unlock(&mutex_2);

        // Acquire mutex_3
        pthread_mutex_lock(&mutex_3);

        // Random code block
        printf("Thread %d executing\n", thread_id);
        fflush(stdout);
        usleep(random() % 1000000);

        // Release mutex_3
        pthread_mutex_unlock(&mutex_3);
    }

    // Release mutex_1
    pthread_mutex_unlock(&mutex_1);

    return NULL;
}

void *thread_2_function(void *arg)
{
    int thread_id = *(int *)arg;
    int i;

    // Acquire mutex_2
    pthread_mutex_lock(&mutex_2);

    for (i = 0; i < 1000000; i++)
    {
        // Acquire mutex_3
        pthread_mutex_lock(&mutex_3);

        // Random code block
        printf("Thread %d executing\n", thread_id);
        fflush(stdout);
        usleep(random() % 1000000);

        // Release mutex_3
        pthread_mutex_unlock(&mutex_3);

        // Acquire mutex_1
        pthread_mutex_lock(&mutex_1);

        // Random code block
        printf("Thread %d executing\n", thread_id);
        fflush(stdout);
        usleep(random() % 1000000);

        // Release mutex_1
        pthread_mutex_unlock(&mutex_1);
    }

    // Release mutex_2
    pthread_mutex_unlock(&mutex_2);

    return NULL;
}

void *thread_3_function(void *arg)
{
    int thread_id = *(int *)arg;
    int i;

    // Acquire mutex_3
    pthread_mutex_lock(&mutex_3);

    for (i = 0; i < 1000000; i++)
    {
        // Acquire mutex_1
        pthread_mutex_lock(&mutex_1);

        // Random code block
        printf("Thread %d executing\n", thread_id);
        fflush(stdout);
        usleep(random() % 1000000);

        // Release mutex_1
        pthread_mutex_unlock(&mutex_1);

        // Acquire mutex_2
        pthread_mutex_lock(&mutex_2);

        // Random code block
        printf("Thread %d executing\n", thread_id);
        fflush(stdout);
        usleep(random() % 1000000);

        // Release mutex_2
        pthread_mutex_unlock(&mutex_2);
    }

    // Release mutex_3
    pthread_mutex_unlock(&mutex_3);

    return NULL;
}