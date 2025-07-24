//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000    // Maximum limit for Prime Number Generator

int main()
{
    int primes[MAX];    // Array to store prime numbers
    int i, j;
    int count = 0;

    // Initialize all array elements to 1
    for (i = 0; i < MAX; i++)
        primes[i] = 1;

    // Sieve of Eratosthenes algorithm to generate prime numbers
    for (i = 2; i * i <= MAX; i++)
    {
        // If i is a prime number
        if (primes[i] == 1)
        {
            // Mark all multiples of i as non-prime
            for (j = i * i; j <= MAX; j += i)
                primes[j] = 0;
        }
    }

    // Display all prime numbers
    for (i = 2; i <= MAX; i++)
    {
        if (primes[i] == 1)
        {
            printf("%d is a Prime Number.\n", i);
            count++;
        }
    }

    printf("Total %d Prime Numbers are generated.\n", count);

    // Clear all data to prevent memory leak
    free(primes);

    // For added security, overwrite primes array with zeros
    for (i = 0; i < MAX; i++)
        primes[i] = 0;

    return 0;
}