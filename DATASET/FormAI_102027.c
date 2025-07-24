//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false; // less than or equal to 1 are not prime
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false; // if there is a factor, not prime
    }
    return true;
}

int main() {
    int n, count = 0;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are:\n", n);

    // Print the prime numbers
    for (int i = 2; count < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");

    return 0;
}