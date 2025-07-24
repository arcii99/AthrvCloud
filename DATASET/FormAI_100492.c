//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>

int isPrime(int number) {
    int i;
    for (i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generatePrimes(int n) {
    int i, j, count = 0;
    printf("The first %d prime numbers are:\n", n);

    for (i = 2; count < n; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
            ++count;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of primes to generate: ");
    scanf("%d", &n);
    generatePrimes(n);
    return 0;
}