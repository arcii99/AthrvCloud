//FormAI DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_STRING_LENGTH 100

pthread_mutex_t mutex;
char strings[MAX_THREADS][MAX_STRING_LENGTH];

void *thread_function(void *arg);

int main()
{
    pthread_t threads[MAX_THREADS];

    int i;
    for (i = 0; i < MAX_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, thread_function, (void *)&i);
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < MAX_THREADS; i++)
    {
        printf("String %d: %s", i + 1, strings[i]);
    }

    return 0;
}

void *thread_function(void *arg)
{
    int thread_id = *(int *)arg;

    pthread_mutex_lock(&mutex);
    printf("Enter string for thread %d: ", thread_id + 1);
    fgets(strings[thread_id], MAX_STRING_LENGTH, stdin);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}