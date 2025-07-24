//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_function(void *id)
{
    int *thread_id = (int *)id;
    
    printf("Thread %d created\n", *thread_id);
    printf("Thread %d doing some work\n", *thread_id);
    printf("Thread %d finished doing work\n", *thread_id);
    
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int rc, i;
    
    printf("Creating %d threads\n", NUM_THREADS);
    
    for(i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]);
        
        if(rc)
        {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }
    
    for(i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads have completed\n");
    
    return 0;
}