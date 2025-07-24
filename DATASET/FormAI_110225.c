//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define BUFFER_SIZE 1000000

int prime_buffer[BUFFER_SIZE];
int prime_count = 0;

int isPrime(int number) {
    int i;
    for (i = 2; i < number; i++) {
        if (number % i == 0 && i != number) {
            return 0;
        }
    }
    return 1;
}

void *calculatePrimes(void *threadId) {
    int i, j;
    int start = *((int *) threadId);
    int end = start + (BUFFER_SIZE / NUM_THREADS);

    for (i = start; i < end; i++) {
        if (isPrime(i) == 1) {
            prime_buffer[prime_count] = i;
            prime_count++;
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i, j;
    int status;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i * (BUFFER_SIZE / NUM_THREADS);
        status = pthread_create(&threads[i], NULL, calculatePrimes, (void *) &thread_ids[i]);
        if (status) {
            printf("ERROR: Unable to create thread %d with status %d\n", i, status);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Found %d prime numbers:\n", prime_count);

    for (i = 0; i < prime_count; i++) {
        printf("%d ", prime_buffer[i]);
    }

    printf("\n");

    return 0;
}