//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 10
#define PRIME_LIMIT 1000000

// struct for passing arguments to thread function
typedef struct {
    int start;
    int end;
} ThreadArgs;

// global variables
bool isPrime[PRIME_LIMIT+1]; // array to store prime numbers
int primeCount = 0; // counter for number of prime numbers found
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex for locking when updating primeCount

// thread function to find prime numbers within a range
void *findPrimes(void *args) {
    ThreadArgs *threadArgs = (ThreadArgs *) args;
    int start = threadArgs->start;
    int end = threadArgs->end;

    for (int i = start; i <= end; i++) {
        if (!isPrime[i]) continue; // already marked as not prime
        for (int j = i*2; j <= PRIME_LIMIT; j += i) {
            isPrime[j] = false;
        }
        pthread_mutex_lock(&mutex);
        primeCount++;
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadArgs threadArgs[MAX_THREADS];
    int threadsCount;

    // initialize isPrime array
    for (int i = 2; i <= PRIME_LIMIT; i++) {
        isPrime[i] = true;
    }

    // get user input for number of threads to use
    printf("Enter number of threads to use (1-10): ");
    scanf("%d", &threadsCount);
    if (threadsCount < 1 || threadsCount > 10) {
        printf("Invalid input. Number of threads must be between 1 and 10.\n");
        return 1;
    }

    // divide prime number range into equal parts for each thread
    int range = PRIME_LIMIT / threadsCount;
    for (int i = 0; i < threadsCount; i++) {
        threadArgs[i].start = i * range + 2;
        threadArgs[i].end = (i == threadsCount-1) ? PRIME_LIMIT : threadArgs[i].start + range - 1;
        pthread_create(&threads[i], NULL, findPrimes, (void *) &threadArgs[i]);
    }

    // wait for threads to finish
    for (int i = 0; i < threadsCount; i++) {
        pthread_join(threads[i], NULL);
    }

    // print prime numbers found
    printf("Prime numbers found:\n");
    for (int i = 2; i <= PRIME_LIMIT; i++) {
        if (isPrime[i]) printf("%d\n", i);
    }
    printf("Total prime numbers found: %d\n", primeCount);

    return 0;
}