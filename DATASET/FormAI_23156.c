//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: statistical
#include <stdio.h>

int main() {
    int i, j, n, isPrime;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The prime numbers from 1 to %d are:\n", n);

    // loop through numbers 1 to n
    for (i = 2; i <= n; i++) {
        isPrime = 1; // assume number is prime
        // loop through all numbers from 2 to i-1
        for (j = 2; j < i; j++) {
            // if i is divisible by j, it is not prime
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        // if isPrime is still 1, i is prime
        if (isPrime == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}