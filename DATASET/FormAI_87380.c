//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 10 // number of threads to create

// a struct to hold data passed to the thread function
typedef struct {
    int id; // thread id
    int count; // number of iterations
} ThreadData;

// thread function that prints thread id and count
void* printThreadIdAndCount(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    for (int i = 0; i < data->count; i++) {
        printf("Thread %d: iteration %d\n", data->id, i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_COUNT]; // array to hold threads
    ThreadData threadData[THREAD_COUNT]; // array to hold thread data

    // create threads and pass data
    for (int i = 0; i < THREAD_COUNT; i++) {
        threadData[i].id = i;
        threadData[i].count = i + 1;

        int returnVal = pthread_create(&threads[i], NULL, printThreadIdAndCount, (void*) &threadData[i]);
        if (returnVal != 0) {
            printf("Error creating thread %d: return code %d\n", i, returnVal);
            exit(EXIT_FAILURE);
        }
    }

    // join threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        int returnVal = pthread_join(threads[i], NULL);
        if (returnVal != 0) {
            printf("Error joining thread %d: return code %d\n", i, returnVal);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads completed.\n");

    return 0;
}