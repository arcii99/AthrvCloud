//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: single-threaded
#include <stdio.h>

// function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// function to generate prime numbers up to n
void generatePrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Prime numbers up to %d:\n", n);
    generatePrimes(n);
    return 0;
}