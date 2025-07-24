//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 4
#define ARRAY_SIZE 1000000

int sum = 0;
int arr[ARRAY_SIZE];

void *calculate_sum(void *arg) {
    int tid = *(int*)arg;
    int start = tid * (ARRAY_SIZE / THREAD_COUNT);
    int end = start + (ARRAY_SIZE / THREAD_COUNT);

    for (int i = start; i < end; i++) {
        sum += arr[i];
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int tids[THREAD_COUNT];

    // initialize array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // create threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, calculate_sum, (void*)&tids[i]);
    }

    // wait for threads to finish
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The sum of the array is: %d\n", sum);

    return 0;
}