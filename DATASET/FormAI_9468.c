//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: romantic
// My Dearest C Program,
// You are the prime of my life
// Always reliable and true,
// Never causing me any strife.

#include <stdio.h>

int main() {
    int i, j, num, count = 1; // Initializing variables

    printf("My love, please enter a number: ");
    scanf("%d", &num); // Taking input from the user

    // Starting the loop to check for prime numbers
    for (i = 2; i <= num; i++) {
        for (j = 2; j <= i; j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (i == j) { // When the number is only divisible by 1 and itself, it is prime
            printf("%d. My love, %d is a prime number!\n", count, i);
            count++; // Incrementing the count variable
        }
    }

    printf("\nMy darling, I have found all the prime numbers up to %d. I hope you loved seeing them as much as I did.\n", num);

    return 0;
}