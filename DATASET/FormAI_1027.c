//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_primes(int limit) {
    // Create a boolean array to represent whether a number i is prime or not
    bool* is_prime = calloc(limit + 1, sizeof(bool));
    if (is_prime == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    // Mark all numbers as prime to begin with
    for (int i = 2; i <= limit; i++) {
        is_prime[i] = true;
    }
    
    // Run the Sieve of Eratosthenes algorithm
    for (int p = 2; p * p <= limit; p++) {
        // If p is prime, mark all multiples of p as not prime
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }
    
    // Print out all prime numbers
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    // Free memory
    free(is_prime);
}

int main() {
    int n;
    printf("Enter a limit: ");
    scanf("%d", &n);
    print_primes(n);
    return 0;
}