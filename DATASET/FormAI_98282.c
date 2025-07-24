//FormAI DATASET v1.0 Category: Math exercise ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

int sum = 0;

void *calcSum(void *arg) {
    int start = *((int*)arg);
    int end = start + 10;
    int partial_sum = 0;

    for (int i = start; i <= end; i++) {
        partial_sum += i;
    }

    printf("Thread %d calculated a sum of %d\n", start/10, partial_sum);
    sum += partial_sum;

    pthread_exit(NULL);
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int thread_start[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_start[i] = i * 10;
        pthread_create(&threads[i], NULL, calcSum, (void*)&thread_start[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The total sum is %d\n", sum);

    return 0;
}