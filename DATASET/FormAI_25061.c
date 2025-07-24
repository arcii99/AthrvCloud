//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: artistic
#include <stdio.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to generate prime numbers
void generatePrimes(int n) {
    printf("The prime numbers between 2 and %d are:\n", n);

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");
}

int main() {
    int n;

    printf("Enter a number to generate prime numbers up to: ");
    scanf("%d", &n);

    generatePrimes(n);

    return 0;
}