//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: enthusiastic
#include <stdio.h>

// Function to check if the given number is prime
int isPrime(int n) {
    // Edge cases
    if (n <= 1) {
        return 0;
    }
    if (n == 2 || n == 3) {
        return 1;
    }
    // Check if the number is divisible by any number from 2 to the square root of the number
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate prime numbers up to a given limit
void genPrimeNumbers(int limit) {
    int count = 0; // Counter for the number of prime numbers generated
    printf("The prime numbers up to %d are:\n", limit);
    // Check each number from 2 to the limit
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n\nTotal number of prime numbers generated: %d", count);
}

int main() {
    int limit;
    printf("Enter the limit up to which you want to generate prime numbers: ");
    scanf("%d", &limit);
    genPrimeNumbers(limit);
    return 0;
}