//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int limit, i, j;
    bool isPrime;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);
    int primeNumbers[limit];
    int count = 0;
    // 2 is the smallest prime number
    primeNumbers[count++] = 2;
    // Check each number in the limit
    for (i=3; i<=limit; i+=2) {
        isPrime = true;
        // Check if the number is divisible by any other number from 2 to i/2
        for (j=2; j<=i/2; j++) {
            if (i % j == 0) {
                // The number is not prime
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primeNumbers[count++] = i;
        }
    }
    printf("There are %d prime numbers between 2 and %d:\n", count, limit);
    for (i=0; i<count; i++) {
        printf("%d ", primeNumbers[i]);
    }
    printf("\n");

    return 0;
}