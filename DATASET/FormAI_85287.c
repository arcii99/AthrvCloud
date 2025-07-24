//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_PRIMES 100000

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void *generatePrimes(void *arg) {
    int *primeList = (int *) arg;
    int i, currentPrime = 2, count = 0;
    while (count < MAX_PRIMES) {
        if (isPrime(currentPrime)) {
            primeList[count++] = currentPrime;
        }
        currentPrime++;
    }
    pthread_exit(NULL);
}

int main() {
    int primeList[MAX_PRIMES];
    pthread_t primeThread;

    pthread_create(&primeThread, NULL, generatePrimes, (void *) primeList);
    
    int i, count = 0;
    for (i = 0; i < MAX_PRIMES; i++) {
        printf("%d ", primeList[i]);
        count++;
        if (count % 10 == 0) {
            printf("\n");
        }
    }
    
    pthread_join(primeThread, NULL);
    return 0;
}