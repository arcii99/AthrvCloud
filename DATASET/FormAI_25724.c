//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: mathematical
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4

// Function to print the first n Fibonacci numbers
void* fibonacci(void* n)
{
    int num = *(int*)n;
    int fib[num];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < num; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("Fibonacci sequence: ");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", fib[i]);
    }
    printf("\n");

    pthread_exit(NULL);
}

// Function to print the first n prime numbers
void* prime(void* n)
{
    int num = *(int*)n;
    int primes[num];
    int count = 0;
    int i = 2;

    while (count < num)
    {
        int is_prime = 1;
        for (int j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if (is_prime)
        {
            primes[count] = i;
            count++;
        }
        i++;
    }

    printf("Prime sequence: ");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", primes[i]);
    }
    printf("\n");

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int fib_num = 10;
    int prime_num = 5;

    // Create and execute the Fibonacci sequence thread
    pthread_create(&threads[0], NULL, fibonacci, (void*)&fib_num);

    // Create and execute the prime numbers thread
    pthread_create(&threads[1], NULL, prime, (void*)&prime_num);

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Exit the main thread
    pthread_exit(NULL);

    return 0;
}