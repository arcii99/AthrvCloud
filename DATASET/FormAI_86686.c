//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Define a function that will be executed by the thread */
void *thread_function(void *arg) {
    int thread_id = *(int *)arg; // cast the argument back to integer
    printf("Thread %d started.\n", thread_id);
    printf("Thread %d is working...\n", thread_id);
    printf("Thread %d finished.\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[5]; // create an array of 5 thread IDs
    int thread_args[5]; // create an array to store the thread arguments
    int i;

    /* Create 5 threads */
    for (i = 0; i < 5; i++) {
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i])) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    printf("All threads created successfully.\n");

    /* Wait for all threads to finish */
    for (i = 0; i < 5; i++) {
        if (pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread %d\n", i);
            return 2;
        }
    }

    printf("All threads finished.\n");

    return 0;
}