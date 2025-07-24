//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: grateful
#include <stdio.h>
#include <math.h>

int main() {
    int start, end, isPrime, i, j;

    printf("Enter the starting number: ");
    scanf("%d", &start);

    printf("Enter the ending number: ");
    scanf("%d", &end);

    // Loop through the range of numbers
    for (i = start; i <= end; i++) {
        // Skip 1 as it is not a prime number
        if (i == 1)
            continue;

        isPrime = 1;
        // Check if current number is a prime number
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        // Print the prime numbers
        if (isPrime)
            printf("%d is a prime number\n", i);
    }

    return 0;
}