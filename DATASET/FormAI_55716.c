//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUM 4     // total number of threads

// thread function
void *thread_function(void *arg)
{
    int thread_id = *(int*)arg;
    printf("Thread %d is running!\n", thread_id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[THREAD_NUM];
    int thread_args[THREAD_NUM];

    // create threads
    for (int i = 0; i < THREAD_NUM; i++)
    {
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0)
        {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(1);
        }
    }

    // wait for all threads to complete
    for (int i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(1);
        }
        printf("Thread %d has completed.\n", i);
    }

    return 0;
}