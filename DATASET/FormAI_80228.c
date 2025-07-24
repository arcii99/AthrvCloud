//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to be executed by the thread
void *thread_function(void *arg)
{
    int value = *(int*)arg;
    printf("Thread %d started\n", value);
    
    // Critical section
    for (int i = 1; i <= 5; i++) {
        printf("Thread %d is in the critical section.\n", value);
    }

    printf("Thread %d finished\n", value);
    return NULL;
}

int main()
{
    int num_threads = 3;
    pthread_t threads[num_threads];

    // Creation of threads
    for (int i = 0; i < num_threads; i++) {
        int *value = malloc(sizeof(int));
        *value = i;
        pthread_create(&threads[i], NULL, thread_function, value);
    }

    // Join threads to wait for them to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}