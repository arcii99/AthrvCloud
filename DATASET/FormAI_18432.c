//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Puzzling function to determine if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Puzzling function to find the next prime number starting from a certain value
int getNextPrime(int start) {
    int num = start;
    while (1) {
        num++;
        if (isPrime(num)) {
            return num;
        }
    }
}

// Puzzling function to count the number of prime numbers in a range
void *countPrimes(void *threadId) {
    int tid = *(int *) threadId;
    int start = 1 + (tid * 1000000);
    int end = start + 1000000;
    int numPrimes = 0;
    for (int i = start; i < end; i = getNextPrime(i)) {
        numPrimes++;
    }
    printf("Thread %d found %d primes\n", tid, numPrimes);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS];
    int rc;
    for (int i = 0; i < NUM_THREADS; i++) {
        threadIds[i] = i;
        rc = pthread_create(&threads[i], NULL, countPrimes, &threadIds[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    exit(0);
}