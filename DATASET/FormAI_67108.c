//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i <= number / i; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int limit) {
    if (limit <= 1) {
        printf("No prime numbers found\n");
        return;
    }
    printf("The prime numbers between 1 and %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int limit;
    printf("Enter the limit for prime numbers generation: ");
    scanf("%d", &limit);
    generatePrimes(limit);
    return 0;
}