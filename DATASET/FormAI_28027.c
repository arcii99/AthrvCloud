//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *async_function(void *arg);

int main()
{
    pthread_t thread1, thread2; // two thread objects
    
    printf("Creating threads...\n");
    
    // Create first thread
    if(pthread_create(&thread1, NULL, async_function, NULL) != 0)
    {
        perror("Error creating thread 1");
        exit(EXIT_FAILURE);
    }
    
    // Create second thread
    if(pthread_create(&thread2, NULL, async_function, NULL) != 0)
    {
        perror("Error creating thread 2");
        exit(EXIT_FAILURE);
    }
    
    // Wait for threads to complete
    if(pthread_join(thread1, NULL) != 0)
    {
        perror("Error joining thread 1");
        exit(EXIT_FAILURE);
    }
    
    if(pthread_join(thread2, NULL) != 0)
    {
        perror("Error joining thread 2");
        exit(EXIT_FAILURE);
    }
    
    printf("Threads completed!\n");
    
    return 0;
}

void *async_function(void *arg)
{
    printf("Thread started...\n");
    sleep(2);
    printf("Thread done!\n");
    return NULL;
}