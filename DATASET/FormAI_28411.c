//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define ARRAY_SIZE 100

int array[ARRAY_SIZE];
int sum = 0;
pthread_mutex_t mutex;

void *sum_array(void *arg)
{
    int thread_sum = 0;
    int start = *(int *)arg;
    for (int i = start; i < start + (ARRAY_SIZE / MAX_THREADS); i++)
    {
        thread_sum += array[i];
    }
    pthread_mutex_lock(&mutex);
    sum += thread_sum;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[MAX_THREADS];
    pthread_attr_t attr;
    int start[MAX_THREADS];

    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = i + 1;
    }

    for (int i = 0; i < MAX_THREADS; i++)
    {
        start[i] = i * (ARRAY_SIZE / MAX_THREADS);
        pthread_create(&threads[i], &attr, sum_array, &start[i]);
    }

    pthread_attr_destroy(&attr);

    for (int i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("The sum of the array is %d.\n", sum);

    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
}