//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: mathematical
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>

#define NUM_THREADS 4

pthread_t threads[NUM_THREADS];
int task_list[NUM_THREADS + 1];
int prime_numbers[NUM_THREADS + 1];

void *calculatePrimes(void *threadId) {
    int tid = *(int*)threadId;
    int start = task_list[tid];
    int end;
    if (tid == NUM_THREADS)
        end = task_list[tid + 1];
    else
        end = task_list[tid + 1] - 1;

    int count = 0, isPrime;

    for (int i = start; i <= end; i++) {
        isPrime = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            count++;
        }
    }

    prime_numbers[tid] = count;

    pthread_exit(NULL);
}

int main() {
    int n, rangeStart = 1, rangeEnd, tasksPerThread, sumOfPrimes = 0;

    printf("Enter the range of prime numbers to search for: ");
    scanf("%d", &n);

    rangeEnd = n;

    tasksPerThread = ceil((double)(rangeEnd - rangeStart + 1) / NUM_THREADS);

    printf("Creating %d threads to search for prime numbers between %d and %d\n", NUM_THREADS, rangeStart, rangeEnd);

    for (int i = 1; i <= NUM_THREADS; i++) {
        task_list[i] = rangeStart + ((i - 1) * tasksPerThread);
    }
    task_list[NUM_THREADS + 1] = rangeEnd + 1;
    
    for (int i = 0; i < NUM_THREADS; i++) {
        int* tid = malloc(sizeof(int));
        *tid = i + 1;
        pthread_create(&threads[i], NULL, calculatePrimes, (void *)tid);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 1; i <= NUM_THREADS; i++) {
        printf("Thread %d found %d prime numbers between %d and %d\n", i, prime_numbers[i], task_list[i], task_list[i+1]-1);
        sumOfPrimes += prime_numbers[i];
    }

    printf("Total number of prime numbers found: %d\n", sumOfPrimes);

    pthread_exit(NULL);
}