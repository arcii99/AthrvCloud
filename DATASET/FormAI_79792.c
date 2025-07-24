//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    printf("Ah, Watson, good to see you again! I've been working on something quite fascinating - a prime number generator in C. I'd like to run through it with you to see if you can make sense of it.\n");
    int num, i, isPrime;

    printf("Enter a maximum number to generate primes up to: ");
    scanf("%d", &num);
    printf("Great, let's get started!\n");

    // Loop through all numbers up to the user's input
    for (i = 2; i <= num; i++) {
        isPrime = 1; // Assume the number is prime until proven otherwise

        // Check if the number is divisible by any number other than 1 and itself
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0; // Set isPrime to false if the number is divisible by any number other than 1 and itself
                break;
            }
        }

        // If isPrime is still true, print the number as a prime
        if (isPrime == 1) {
            printf("%d ", i);
        }
    }

    printf("\nAnd there you have it, Watson - a prime number generator in C! Quite useful, don't you think?\n");
    return 0;
}