//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, i, j, count = 0;
    bool *isPrime;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Allocate memory for boolean flag array
    isPrime = calloc(n+1, sizeof(bool));

    // Initialize all flags to true
    for (i = 2; i <= n; i++) {
        isPrime[i] = true;
    }

    // Perform sieve of Eratosthenes algorithm
    for (i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Count and print all prime numbers found
    for (i = 2; i <= n; i++) {
        if (isPrime[i]) {
            printf("%d is prime\n", i);
            count++;
        }
    }

    printf("Found %d prime numbers in range 1 to %d\n", count, n);

    // Free memory
    free(isPrime);

    return 0;
}