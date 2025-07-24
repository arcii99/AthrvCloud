//FormAI DATASET v1.0 Category: Funny ; Style: single-threaded
#include <stdio.h>

#define N 10

int main() {
    int array[N] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int i;
    printf("The first %d prime numbers are: ", N);
    for (i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\nLet's generate some more primes using the Sieve of Eratosthenes algorithm.\n\n");

    int sieve[N];  // Initialize the sieve with all numbers from 1 to N.
    for (i = 0; i < N; i++) {
        sieve[i] = i + 1;
    }

    int j;
    for (i = 1; i < N; i++) {  // Loop through numbers 2 to N.
        if (sieve[i] != 0) {  // If sieve[i] is still a prime number (not crossed out).
            int p = sieve[i];
            printf("%d ", p);  // Print out the prime number.

            // Cross out all multiples of p.
            for (j = i + p; j < N; j += p) {
                sieve[j] = 0;
            }
        }
    }

    printf("\n\nThat's all folks! Exiting program...\n");

    return 0;
}