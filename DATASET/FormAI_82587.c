//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: cheerful
#include <stdio.h>

int main()
{
    printf("\nHello, I am your friendly Prime Number Generator!\nLet's generate some primes together!\n");

    int n, i, flag;

    printf("\nEnter a number greater than 1: ");
    scanf("%d", &n);

    while (n <= 1) {
        printf("\nInvalid input. Please enter a number greater than 1: ");
        scanf("%d", &n);
    }

    printf("\nYay! %d is a valid number! Let's find all the prime numbers less than or equal to %d:\n", n, n);

    // Check each number between 2 and n for primality
    for (i = 2; i <= n; i++) {
        flag = 0;

        // Check if i is prime
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }

        // If i is prime, print it
        if (flag == 0) {
            printf("%d ", i);
        }
    }

    printf("\n\nThank you for using our Prime Number Generator! Have a great day!\n");

    return 0;
}