//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

// Maximum number of primes to generate
#define MAX_PRIMES 100

// Struct for passing arguments to the thread function
typedef struct
{
    int start;
    int end;
    int* primes;
    int* num_primes;
} prime_args;

// Function for finding primes
void* find_primes(void* args)
{
    prime_args* p_args = (prime_args*) args;
    int start = p_args->start;
    int end = p_args->end;
    int* primes = p_args->primes;
    int* num_primes = p_args->num_primes;

    // Loop through the range of numbers
    for (int num = start; num <= end; num++)
    {
        bool is_prime = true;

        // Check if the number is divisible by any previous primes
        for (int i = 0; i < *num_primes; i++)
        {
            if (num % primes[i] == 0)
            {
                is_prime = false;
                break;
            }
        }

        // If the number is prime, add it to the list
        if (is_prime)
        {
            primes[*num_primes] = num;
            (*num_primes)++;
        }
    }

    pthread_exit(NULL);
}

int main()
{
    int primes[MAX_PRIMES];
    int num_primes = 0;

    // Create the threads
    pthread_t thread1, thread2;
    prime_args args1 = {2, 499, primes, &num_primes};
    prime_args args2 = {500, 999, primes, &num_primes};
    pthread_create(&thread1, NULL, find_primes, (void*) &args1);
    pthread_create(&thread2, NULL, find_primes, (void*) &args2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print out the primes
    for (int i = 0; i < num_primes; i++)
    {
        printf("%d ", primes[i]);
    }

    return 0;
}