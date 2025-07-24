//FormAI DATASET v1.0 Category: Scientific ; Style: beginner-friendly
#include <stdio.h>

/* This program will take an input integer and print all the prime 
 * numbers less than or equal to the input number.
 */

int main() {
    int num, i, j, isPrime;

    printf("Enter a number: ");
    scanf("%d", &num);

    // We will iterate from 2 to the input number
    for (i = 2; i <= num; i++) {

        // Check if i is prime
        isPrime = 1;  // Assume i is prime

        // Check if i is divisible by any number less than i
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;  // i is not prime
                break;
            }
        }

        // If i is prime, print it
        if (isPrime) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}