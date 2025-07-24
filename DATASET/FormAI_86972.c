//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Ada Lovelace
/* 
 * Ada Lovelace Style Threading Library Implementation Example
 * by [your name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *arg)
{
    // code to be executed by each threaded function
    printf("Hello World, this is thread %d\n", *(int *)(arg));
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_id[NUM_THREADS]; // array to store threads
    int thread_args[NUM_THREADS]; // array to store thread arguments
    int i;

    printf("Creating %d threads...\n", NUM_THREADS);

    // create threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        if (pthread_create(&thread_id[i], NULL, thread_function, &thread_args[i]) != 0) {
	    fprintf(stderr, "Error creating thread\n");
	    exit(-1);
	}
    }
    
    // join threads
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(thread_id[i], NULL) != 0) {
	    fprintf(stderr, "Error joining thread\n");
	    exit(-1);
	}
    }
    
    printf("All threads completed.\n");
    return 0;
}