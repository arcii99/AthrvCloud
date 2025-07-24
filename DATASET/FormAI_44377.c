//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: automated
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

int max_number = 1000000;  // the upper bound of numbers to check for prime
int num_threads = 4;  // number of threads to create

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void* prime_check(void* arg) {
    int* info = (int*) arg;
    int start = info[0];
    int end = info[1];
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d is prime\n", i);
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[num_threads];
    int range = max_number / num_threads;
    int start = 1;
    int info[num_threads][2];
    for (int i = 0; i < num_threads; i++) {
        info[i][0] = start;
        info[i][1] = start + range - 1;
        start += range;
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, prime_check, (void*) info[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}