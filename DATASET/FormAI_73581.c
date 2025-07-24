//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: creative
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime or not
bool isPrime(int n) {
    // Base cases
    if (n <= 1) return false;
    if (n <= 3) return true;

    // Check if n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Check if n is divisible by any prime number greater than 3
    for (int i = 5; i*i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

// Function to generate prime numbers up to a given limit
void generatePrimes(int limit) {
    printf("The prime numbers up to %d are:\n", limit);

    // Check if 2 is prime
    if (limit >= 2) {
        printf("2 ");
    }

    // Check all odd numbers
    for (int i = 3; i <= limit; i = i + 2) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int limit;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    generatePrimes(limit);

    return 0;
}