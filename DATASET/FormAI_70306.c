//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: intelligent
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 4
#define THREAD_PARAMS "Parameter for thread %d"

void* printThreadId(void* threadID)
{
    int id = *(int*)threadID;
    printf("Thread %d is running with %s\n", id, THREAD_PARAMS);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int threadParams[NUM_THREADS];

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        threadParams[i] = i;
        printf("Creating thread %d...\n", i);
        int resultCode = pthread_create(&threads[i], NULL, printThreadId, (void*)&threadParams[i]);
        if (resultCode) {
            printf("Error creating thread %d, return code: %d\n", i, resultCode);
            exit(-1);
        }
    }

    printf("All threads are created successfully.\n");

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d is done.\n", i);
    }

    return 0;
}