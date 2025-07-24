//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: all-encompassing
#include <stdio.h>

// function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// function to generate prime numbers up to a given limit
int generatePrimes(int limit) {
    int count = 0;
    printf("The prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal number of primes: %d\n", count);
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    generatePrimes(limit);
    return 0;
}