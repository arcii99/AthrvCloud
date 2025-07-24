//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>
#include <stdbool.h>

// function to check if a number is prime
bool isPrime(int num) {
    // 0 and 1 are not prime numbers
    if (num < 2)
        return false;

    // check for factors from 2 to num/2
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

// function to generate prime numbers up to a given limit
void generatePrimes(int limit) {
    printf("The prime numbers up to %d are:\n", limit);

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }
}

int main() {
    int limit;
    printf("Enter a limit to generate prime numbers up to: ");
    scanf("%d", &limit);

    generatePrimes(limit);

    return 0;
}