//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg)
{
    int *thread_id = (int *)arg;

    pthread_mutex_lock(&mutex);
    printf("Thread %d is running.\n", *thread_id);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t threads[THREAD_COUNT];
    int thread_ids[THREAD_COUNT];

    // Create threads
    for (i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}