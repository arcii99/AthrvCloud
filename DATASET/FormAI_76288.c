//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: enthusiastic
#include <stdio.h>

int main() {
    int n; // Number to find the prime factorization for
    printf("Enter a number: ");
    scanf("%d", &n);

    int i, j;
    int is_prime; // Flag variable to determine if the number is prime

    // Check each number from 2 to n for primality
    for (i = 2; i <= n; i++) {
        is_prime = 1;

        // Check if i is prime by testing if it is divisible by any number from 2 to i-1
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        // If i is prime, print it
        if (is_prime) {
            printf("%d ", i);
        }
    }

    return 0;
}