//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUM 1000000

int main()
{
    bool is_prime[MAX_NUM];
    int i, j, n;

    // Initialize all numbers as prime
    for (i = 2; i < MAX_NUM; i++) {
        is_prime[i] = true;
    }

    // Sieve of Eratosthenes algorithm to mark non-primes
    for (i = 2; i <= sqrt(MAX_NUM); i++) {
        if (is_prime[i]) {
            for (j = i*i; j < MAX_NUM; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Print all prime numbers
    n = 0;
    for (i = 2; i < MAX_NUM; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
            n++;
            if (n % 10 == 0) {
                printf("\n");
            }
        }
    }
    printf("\n");

    return 0;
}