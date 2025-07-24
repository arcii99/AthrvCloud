//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *doWork(void *threadID) // thread function
{
    int *id_ptr, task_id;

    id_ptr = (int *)threadID;
    task_id = *id_ptr;

    printf("Thread %d is starting...\n", task_id);
    sleep(1); // do some work
    printf("Thread %d is done.\n", task_id);

    pthread_exit(NULL); // exit thread
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS];
    int i;

    printf("Creating %d threads...\n", NUM_THREADS);

    for(i = 0; i < NUM_THREADS; i++)
    {
        threadIds[i] = i + 1;
        pthread_create(&threads[i], NULL, doWork, &threadIds[i]);
    }

    printf("All %d threads created.\n", NUM_THREADS);

    for(i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Thread %d has joined.\n", i + 1);
    }

    printf("All threads completed.\n");

    return 0;
}