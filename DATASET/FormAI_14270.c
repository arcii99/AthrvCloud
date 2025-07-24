//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sieve(int n) {
    bool *is_prime = calloc(n+1, sizeof(bool));
    int i, j;

    // initialize array
    for (i = 2; i <= n; i++) {
        is_prime[i] = true;
    }

    // loop through array and mark non-primes
    for (i = 2; i*i <= n; i++) {
        if (is_prime[i]) {
            for (j = i*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // print out prime numbers
    printf("Prime numbers between 2 and %d:\n", n);
    for (i = 2; i <= n; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }

    free(is_prime);
}

int main() {
    int n;

    printf("Enter a number to find all prime numbers between 2 and that number: ");
    scanf("%d", &n);

    sieve(n);

    return 0;
}