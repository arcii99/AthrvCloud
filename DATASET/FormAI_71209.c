//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS_COUNT 10
#define RANGE 100000

int is_prime(int number) {
    if (number < 2) {
        return 0;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

void* generate_primes(void* arg) {
    int thread_num = *(int*) arg;
    int start = thread_num * (RANGE / THREADS_COUNT);
    int end = start + (RANGE / THREADS_COUNT);
    
    printf("Thread %d starting at %d and ending at %d\n", thread_num, start, end);
    
    for (int i = start; i < end; i++) {
        if (is_prime(i)) {
            printf("%d is prime\n", i);
        }
    }
    
    printf("Thread %d finished\n", thread_num);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS_COUNT];
    int thread_ids[THREADS_COUNT];
    
    for (int i = 0; i < THREADS_COUNT; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, generate_primes, &thread_ids[i]);
    }
    
    for (int i = 0; i < THREADS_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}