//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define THREADS 4 // Number of threads
#define RANGE 10000 // Range of numbers to check for primes

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void* prime_generator(void* arg) {
    int start = *((int*) arg);
    int end = start + RANGE/THREADS;
    printf("Thread %d processing numbers %d to %d\n", start, start, end);

    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d is a prime number\n", i);
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    int start[THREADS];

    for (int i = 0; i < THREADS; i++) {
        start[i] = RANGE/THREADS * i;
        pthread_create(&threads[i], NULL, prime_generator, &start[i]);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}