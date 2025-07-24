//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// This is our thread function that will be called when the thread starts
void *thread_function(void *arg)
{
    int tid = *(int *)arg; // Cast void pointer to int pointer and dereference to get thread id
    printf("Thread %d starting...\n", tid);
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Thread %d: %d\n", tid, i);
        sleep(1); // Sleep for one second to simulate work
    }
    printf("Thread %d done.\n", tid);
    pthread_exit(NULL);
}

int main()
{
    int i;
    int num_threads = 3;
    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    // Create threads
    for (i = 0; i < num_threads; i++)
    {
        thread_ids[i] = i; // Store the thread id in an array
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    // Join threads
    for (i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads done.\n");

    return 0;
}