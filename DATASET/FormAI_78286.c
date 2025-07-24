//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void *thread_function(void *arg);

int main()
{
    pthread_t threads[NUM_THREADS];
    int i;
    
    for(i = 0; i < NUM_THREADS; i++)
    {
        int ret = pthread_create(&threads[i], NULL, thread_function, (void *)i);
        
        if(ret != 0)
        {
            printf("Error: pthread_create failed with code %d\n", ret);
            exit(EXIT_FAILURE);
        }
    }
    
    for(i = 0; i < NUM_THREADS; i++)
    {
        int ret = pthread_join(threads[i], NULL);
        
        if(ret != 0)
        {
            printf("Error: pthread_join failed with code %d\n", ret);
            exit(EXIT_FAILURE);
        }
    }
    
    printf("All threads completed successfully\n");
    
    return 0;
}

void *thread_function(void *arg)
{
    int thread_id = (int)arg;
    printf("Thread %d started\n", thread_id);
    
    // Perform some work here...
    
    printf("Thread %d finished\n", thread_id);
    
    pthread_exit(NULL);
}