//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>

int main() {
    int max, i, j, is_prime;

    printf("Enter the maximum number: ");
    scanf("%d", &max);

    printf("The prime numbers from 2 to %d are:\n", max);

    // loop through every number from 2 to max
    for (i = 2; i <= max; i++) {
        is_prime = 1;

        // check if i is divisible by any number from 2 to i-1
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        // if i is prime, print it out
        if (is_prime == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}