//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t mutex_thread;
int counter = 0;

void *thread_function(void *argument)
{
    int id = *(int*) argument;
    printf("Thread %d starting...\n", id);
    
    pthread_mutex_lock(&mutex_thread);
    counter++;
    printf("Thread %d incrementing counter to %d...\n", id, counter);
    pthread_mutex_unlock(&mutex_thread);
    
    printf("Thread %d ending...\n", id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int id[NUM_THREADS];
    int i, result;
    
    pthread_mutex_init(&mutex_thread, NULL);
    
    for(i = 0; i < NUM_THREADS; i++)
    {
        id[i] = i;
        result = pthread_create(&threads[i], NULL, thread_function, &id[i]);
        
        if(result != 0)
        {
            perror("Thread creation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    
    for(i=0; i<NUM_THREADS; i++)
    {
        result = pthread_join(threads[i], NULL);
        if(result != 0)
        {
            perror("Thread join failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    
    pthread_mutex_destroy(&mutex_thread);
    
    printf("Finished!\n");
    return 0;
}