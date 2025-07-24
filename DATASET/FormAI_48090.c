//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: safe
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5

pthread_mutex_t lock;

int shared_variable = 0;

void *thread_function(void *thread_id)
{
    int tid = *((int*)thread_id);

    pthread_mutex_lock(&lock);

    printf("Thread %d is now running!\n", tid);
    printf("Shared Variable: %d\n", shared_variable);

    shared_variable++;

    printf("Incremented Shared Variable: %d\n", shared_variable);

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;

    if(pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Error: Mutex Initialization Failed!\n");
        return -1;
    }

    for(i = 0; i < NUM_THREADS; ++i)
    {
        thread_ids[i] = i;
        int return_code = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);

        if(return_code)
        {
            printf("Error: Unable to create thread, %d\n", return_code);
            exit(-1);
        }
    }

    for(i = 0; i < NUM_THREADS; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}