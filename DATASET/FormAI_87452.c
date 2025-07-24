//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIME 100000

int prime[MAX_PRIME];

int main()
{
    int i, j, n, is_prime;

    /* Populate the array with potential prime numbers */
    for(i = 2; i < MAX_PRIME; i++)
    {
        prime[i] = 1;
    }

    /* Sieve of Eratosthenes algorithm to identify prime numbers */
    for(i = 2; i * i < MAX_PRIME; i++)
    {
        if(prime[i])
        {
            for(j = i * i; j < MAX_PRIME; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    /* Print out the prime numbers */
    printf("Prime numbers up to %d:\n", MAX_PRIME - 1);
    printf("2, ");

    /* Handle all other numbers that are potentially prime */
    for(i = 3; i < MAX_PRIME; i += 2)
    {
        if(prime[i])
        {
            printf("%d, ", i);
        }
    }

    printf("\n");

    return 0;
}