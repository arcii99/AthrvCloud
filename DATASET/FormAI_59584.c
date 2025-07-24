//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>

int main() {
    int num, i, divisor;
    bool isPrime;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // 1 is not a prime number
    if (num == 1) {
        printf("1 is neither a prime nor a composite number.\n");
    } else {
        printf("The prime numbers between 1 and %d are:\n", num);

        // loop through all numbers from 2 to num inclusive
        for (i = 2; i <= num; i++) {
            isPrime = true;

            // check if the current number is divisible by any number from 2 to i - 1
            for (divisor = 2; divisor < i; divisor++) {
                if (i % divisor == 0) {
                    isPrime = false;
                    break;
                }
            }

            // if the current number is prime, print it
            if (isPrime) {
                printf("%d ", i);
            }
        }
    }

    return 0;
}