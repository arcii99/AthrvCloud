//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *thread_id) 
{
    int id = *((int *) thread_id);
    printf("Hello from thread %d \n", id);
    pthread_exit(NULL);
}

int main() 
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS], i, result;

    for (i = 0; i < NUM_THREADS; i++) 
    {
        thread_ids[i] = i;
        result = pthread_create(&threads[i], NULL, &thread_function, &thread_ids[i]);

        if(result != 0) 
        {
            perror("Thread creation failed\n");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) 
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads joined\n");
    exit(EXIT_SUCCESS);
}