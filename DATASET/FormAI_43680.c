//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 8
#define MAX_NUMBER 10000000

bool sieve[MAX_NUMBER];

void *sieve_thread(void *start_void_ptr)
{
    int start = *((int *)start_void_ptr);
    int end = start + MAX_NUMBER/MAX_THREADS;

    for (int i = 2; i*i < MAX_NUMBER; i++) {
        if (sieve[i]) {
            for (int j = i*i; j < MAX_NUMBER; j += i) {
                sieve[j] = false;
            }
        }
    }

    for (int i = start; i < end; i++) {
        if (sieve[i]) {
            printf("%d\n", i);
        }
    }

    return NULL;
}

int main()
{
    for (int i = 2; i < MAX_NUMBER; i++) {
        sieve[i] = true;
    }

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        int *start = malloc(sizeof(int));
        *start = (MAX_NUMBER/MAX_THREADS)*i;
        pthread_create(&threads[i], NULL, sieve_thread, start);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}