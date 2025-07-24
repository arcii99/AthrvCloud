//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: careful
#include <stdio.h>

int main() {
    int i, j, n, isPrime;

    printf("Enter the number n for which you want to generate prime numbers: ");
    scanf("%d", &n);
    printf("Prime numbers from 2 to %d are: \n", n);

    // Loop through all numbers from 2 to n
    for (i = 2; i <= n; i++) {
        isPrime = 1;

        // Check if i is prime or not
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        // If i is prime, print it
        if (isPrime == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}