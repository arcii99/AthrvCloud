//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>

#define NUM_THREADS 4

// Function to check for prime numbers
void *is_prime(void *thread_id) {
    long tid = (long)thread_id;
    printf("Thread %ld starting...\n", tid);

    int num = 2;
    while (num <= tid) {
        int isPrime = 1;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d is prime (found by Thread %ld)\n", num, tid);
        }
        num++;
    }

    printf("Thread %ld ending...\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, t;
    long tid;
    
    for (t = 0; t < NUM_THREADS; t++) {
        tid = t + 1;
        printf("Creating thread %ld...\n", tid);
        rc = pthread_create(&threads[t], NULL, is_prime, (void *) tid);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("Exiting main thread...\n");
    pthread_exit(NULL);
}