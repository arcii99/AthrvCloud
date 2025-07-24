//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: modular
// Prime number generator program
// By [Your Name]

#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to generate primes up to a given number
void generate_primes(int limit) {
    printf("Generating prime numbers up to %d\n", limit);

    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int limit;

    printf("Enter limit: ");
    scanf("%d", &limit);

    generate_primes(limit);

    return 0;
}