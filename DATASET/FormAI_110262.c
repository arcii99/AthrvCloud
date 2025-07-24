//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 5 // We will create 5 threads

// Define the function that will be run in each thread
void *print_message(void *thread_id) {
    int tid = *(int *)thread_id;
    printf("Thread %d: Hello, World!\n", tid);
    pthread_exit(NULL);
}

int main() {
    // Create an array of threads
    pthread_t threads[THREAD_COUNT];

    // Loop through and create each thread
    for (int i = 0; i < THREAD_COUNT; i++) {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i;
        int ret_val = pthread_create(&threads[i], NULL, print_message, (void *)thread_id);
        if (ret_val != 0) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }

    // Wait for each thread to finish execution
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print a message to signify the end of the program
    printf("All threads have completed execution.\n");

    return 0;
}