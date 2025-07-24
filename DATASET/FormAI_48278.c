//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

// Define a thread function that prints the thread ID and exits
void *printThreadID(void *threadID) {
    printf("Thread ID: %d\n", *((int*) threadID));
    pthread_exit(NULL);
}

int main() {
    // Declare thread variables
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];
    
    // Initialize and create threads
    for(int i = 0; i < NUM_THREADS; i++) {
        threadIDs[i] = i+1;
        int rc = pthread_create(&threads[i], NULL, printThreadID, &threadIDs[i]);
        if(rc) {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    // Wait for threads to finish executing
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads have completed execution!\n");
    
    return 0;
}