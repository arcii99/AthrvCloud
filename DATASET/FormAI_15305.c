//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>

/* Function to check if a number is prime or not */
int isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i=2; i<num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

/* Function to generate and print prime numbers up to a given limit */
void generatePrimeNumbers(int limit) {
    printf("Prime Numbers up to %d:\n", limit);
    for (int i=2; i<=limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

/* Main function */
int main() {
    int maxLimit;
    printf("Enter the maximum limit to generate prime numbers: ");
    scanf("%d", &maxLimit);

    generatePrimeNumbers(maxLimit);

    return 0;
}