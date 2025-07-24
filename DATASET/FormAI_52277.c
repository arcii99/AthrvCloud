//FormAI DATASET v1.0 Category: Data mining ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 100

int data[ARRAY_SIZE];

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void *primeFinder(void *threadId) {
    long id = (long)threadId;

    for (int i = id; i < ARRAY_SIZE; i += NUM_THREADS) {
        if (isPrime(data[i])) {
            printf("Thread %ld: %d is a prime number\n", id, data[i]);
        } else {
            printf("Thread %ld: %d is not a prime number\n", id, data[i]);
        }
    }

    pthread_exit(NULL);
}


int main() {

    // Populate the data array with random integers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        data[i] = rand() % 1000;
    }

    pthread_t threads[NUM_THREADS];

    // Create the threads
    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, primeFinder, (void *) i);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}