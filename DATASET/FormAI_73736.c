//FormAI DATASET v1.0 Category: Educational ; Style: expert-level
/* This is a program to generate series of prime numbers using Sieve of Eratosthenes 
 * algorithm. It is an efficient method for finding all primes less than n.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN 1 // The minimum number in the list of prime numbers
#define MAX 100 // Maximum number for generating the list of prime numbers

int main()
{
    int p, i;
    bool prime[MAX+1]; // Boolean array to hold the prime numbers

    // Initialise the boolean array with the value true for all the indices
    for (i = MIN; i <= MAX; i++)
        prime[i] = true;

    // Mark all the non-prime numbers beginning from 2
    for (p = 2; p*p <= MAX; p++)
    {
        if (prime[p] == true)
        {
            for (i = p*p; i <= MAX; i += p)
                prime[i] = false;
        }
    }

    // Print all the prime numbers in the list
    printf("The prime numbers less than or equal to %d are:\n", MAX);
    for (i = MIN; i <= MAX; i++)
    {
        if (prime[i] == true)
            printf("%d\n", i);
    }

    return 0;
}