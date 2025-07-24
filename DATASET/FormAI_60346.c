//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
#define NUM_THREADS 5
 
// Function to be executed by threads
void *thread_function(void *arg)
{
    int id = *(int*)arg;
    printf("Thread %d executing...\n", id);
    pthread_exit(NULL);
}
 
int main()
{
    int i, scope, policy;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t thread_attr;
 
    // Initialize thread attributes object
    pthread_attr_init(&thread_attr);
 
    // Get default scope and scheduling policy
    pthread_attr_getscope(&thread_attr, &scope);
    pthread_attr_getschedpolicy(&thread_attr, &policy);
 
    // Set scope to system
    pthread_attr_setscope(&thread_attr, PTHREAD_SCOPE_SYSTEM);
 
    // Set scheduling policy to FIFO
    struct sched_param param;
    pthread_attr_setschedpolicy(&thread_attr, SCHED_FIFO);
    param.sched_priority = 10;
    pthread_attr_setschedparam(&thread_attr, &param);
 
    // Create threads
    for(i=0; i<NUM_THREADS; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        if(pthread_create(&threads[i], &thread_attr, thread_function, (void*)id) != 0)
        {
            printf("Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
 
    // Join threads
    for(i=0; i<NUM_THREADS; i++) {
        if(pthread_join(threads[i], NULL) != 0)
        {
            printf("Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
 
    // Destroy thread attribute object
    pthread_attr_destroy(&thread_attr);
 
    return 0;
}