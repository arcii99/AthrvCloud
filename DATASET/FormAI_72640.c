//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers from 2 to n
void generatePrimes(int n) {
    printf("Prime numbers between 2 and %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter a number to generate all primes from 2 to that number: ");
    scanf("%d", &n);
    generatePrimes(n);
    return 0;
}