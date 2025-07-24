//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 100

int array[ARRAY_SIZE];

void *thread_function(void *arg) {
    int taskid = *(int *) arg;
    int start = taskid * (ARRAY_SIZE / NUM_THREADS);
    int end = start + (ARRAY_SIZE / NUM_THREADS);
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += array[i];
    }
    return (void *) sum;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int taskids[NUM_THREADS];
    void *status;
    int sum = 0;
    // Fill array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10;
    }
    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        taskids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &taskids[i]);
    }
    // Join threads and calculate sum
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], &status);
        sum += (int) status;
    }
    // Print sum
    printf("The sum of the array is %d\n", sum);
    return 0;
}