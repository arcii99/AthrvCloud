//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIMES 100   /* maximum number of primes to generate */

/* function prototype */
int is_prime(int);

int main(void)
{
    int primes[MAX_PRIMES] = { 2 };  /* array to hold primes */
    int n = 1;                       /* current number of primes found */
    int i = 3;                       /* number to test for primality */

    printf("Generating primes...\n");

    /* loop until we have found the maximum number of primes */
    while (n < MAX_PRIMES) {
        if (is_prime(i)) {
            primes[n++] = i;
        }
        i++;
    }

    /* print out the primes */
    for (i = 0; i < MAX_PRIMES; i++) {
        printf("%d ", primes[i]);
        if (i % 10 == 9)        /* print in rows of 10 */
            printf("\n");
    }

    printf("\nDone.\n");

    return 0;
}

/* is_prime: return 1 if n is prime, 0 otherwise */
int is_prime(int n)
{
    int i;

    /* special case for n = 2 */
    if (n == 2)
        return 1;

    /* check if n is divisible by any integer from 2 to sqrt(n) */
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}