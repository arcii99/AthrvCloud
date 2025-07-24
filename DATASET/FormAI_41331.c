//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: scientific
#include <stdio.h>
#include <pthread.h>

// Struct for thread arguments
typedef struct {
    int id;
    double result;
} ThreadArgs;

// Function to be threaded
void *compute(void *arg) {
    ThreadArgs *args = (ThreadArgs *) arg;
    double result = 0.0;
    // Do some long and complex math calculations
    for (int i = 0; i < 10000000; i++) {
        result += i % 2 == 0 ? i : -i;
    }
    args->result = result;
    return NULL;
}

int main() {
    const int numThreads = 4;
    pthread_t threads[numThreads];
    ThreadArgs threadArgs[numThreads];
    double sum = 0.0;
    
    // Create threads
    for (int i = 0; i < numThreads; i++) {
        threadArgs[i].id = i;
        pthread_create(&threads[i], NULL, compute, &threadArgs[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
        sum += threadArgs[i].result;
    }

    printf("Result: %lf\n", sum);

    return 0;
}