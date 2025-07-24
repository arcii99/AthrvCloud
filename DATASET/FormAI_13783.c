//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5 // Number of threads to be created

// Thread function to be executed
void *printThread(void *threadNum) {
    int num = *(int*)threadNum;
    printf("Thread %d is running\n", num);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadNums[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        threadNums[i] = i;
        int status = pthread_create(&threads[i], NULL, printThread, &threadNums[i]);
        if (status) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(1);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        int status = pthread_join(threads[i], NULL);
        if (status) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(1);
        }
    }

    printf("Threads are finished executing\n");
    pthread_exit(NULL);
}