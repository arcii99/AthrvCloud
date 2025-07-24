//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: high level of detail
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

/* Function executed by threads */
void *threadFunction(void *args) {
    int threadId = *(int *) args;
    printf("Thread #%d has started.\n", threadId);
    // Thread logic here...
    printf("Thread #%d has finished.\n", threadId);
    pthread_exit(NULL);
}

/* Main function */
int main() {
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS];
    int i;
    int retVal;
    
    /* Create threads */
    for (i = 0; i < NUM_THREADS; i++) {
        threadIds[i] = i;
        retVal = pthread_create(&threads[i], NULL, threadFunction, &threadIds[i]);
        if (retVal != 0) {
            printf("Error: Unable to create thread #%d.\n", i);
            exit(EXIT_FAILURE);
        }
    }
    
    /* Wait for threads to finish */
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}