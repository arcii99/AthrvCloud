//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, i, j;
    bool isPrime;

    printf("Enter the maximum number to generate primes up to: ");
    scanf("%d", &n);

    // Loop through all the numbers from 2 up to n
    for (i = 2; i <= n; i++) {
        isPrime = true;

        // Loop through all the numbers from 2 up to the square root of i
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                // i is not a prime number
                isPrime = false;
                break;
            }
        }

        // If i is a prime number, print it out
        if (isPrime) {
            printf("%d ", i);
        }
    }

    return 0;
}