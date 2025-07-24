//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multi-threaded
#include <stdatomic.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number to check for prime
#define MAX_NUM 1000000

// Define the size of the buffer
#define BUFFER_SIZE 100

// Shared buffer to store primes
atomic_int prime_buffer[BUFFER_SIZE];

// Current buffer index
atomic_int buffer_index = 0;

// Mutex for synchronizing buffer access
pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to check if a number is prime
bool is_prime(int num)
{
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate primes
void *prime_generator(void *arg)
{
    int start = *((int *)arg);
    for (int num = start; num <= MAX_NUM; num += 2) {
        if (is_prime(num)) {
            pthread_mutex_lock(&buffer_mutex);
            if (buffer_index < BUFFER_SIZE) {
                prime_buffer[buffer_index++] = num;
            }
            pthread_mutex_unlock(&buffer_mutex);
        }
    }
    return NULL;
}

int main()
{
    // Initialize array of thread ids
    pthread_t threads[10];

    // Start the prime generator threads
    for (int i = 0; i < 10; i++) {
        int start = i * (MAX_NUM / 10) + 1;
        pthread_create(&threads[i], NULL, prime_generator, (void *)&start);
    }

    // Wait for all threads to complete
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the primes
    for (int i = 0; i < buffer_index; i++) {
        printf("%d ", prime_buffer[i]);
    }
    printf("\n");

    return 0;
}