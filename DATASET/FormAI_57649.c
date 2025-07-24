//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define THREAD_COUNT 4

int current_prime = 2;

bool is_prime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void* find_primes(void* arg) {
    int thread_id = *(int*)arg;

    while(true) {
        int num = __sync_fetch_and_add(&current_prime, 1);

        if(is_prime(num)) {
            printf("Thread %d found prime: %d\n", thread_id, num);
        }
    }
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int thread_ids[THREAD_COUNT];

    for(int i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, find_primes, &thread_ids[i]);
    }

    for(int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}