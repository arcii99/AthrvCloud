//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: thoughtful
/* This program demonstrates the usage of a custom C threading library implementation
   using POSIX threads. It creates 5 threads and have them print their thread id.

   NOTE: Only tested on Linux */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

/* Thread function: prints the thread id */
void *thread_func(void *arg) {
    printf("Thread id is %u\n", (unsigned int)pthread_self());
    return NULL;
}

/* Entry point */
int main() {
    pthread_t threads[NUM_THREADS];

    /* Create threads */
    for(int i = 0; i < NUM_THREADS; i++) {
        if(pthread_create(&threads[i], NULL, thread_func, NULL) != 0) {
            fprintf(stderr, "Error creating thread\n");
            exit(1);
        }
    }

    /* Waits for threads to finish */
    for(int i = 0; i < NUM_THREADS; i++) {
        if(pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread\n");
            exit(1);
        }
    }

    return 0;
}