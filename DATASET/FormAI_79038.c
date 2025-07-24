//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

int main() {
    int number;
    printf("Enter any positive integer: ");
    scanf("%d", &number);

    // check if the number is less than 2, then it is not a prime number
    if (number < 2) {
        printf("%d is not a prime number\n", number);
        return 0;
    }

    // check if the number is 2, then it is a prime number
    if (number == 2) {
        printf("%d is a prime number\n", number);
        return 0;
    }

    // check if the number is even, then it is not a prime number
    if (number % 2 == 0) {
        printf("%d is not a prime number\n", number);
        return 0;
    }

    // check if the number is odd, then it may be a prime number
    for (int i = 3; i * i <= number; i = i + 2) {
        // check if the number is divisible by any odd number up to its square root
        if (number % i == 0) {
            printf("%d is not a prime number\n", number);
            return 0;
        }
    }

    // if the number is not divisible by any odd number up to its square root, then it is a prime number
    printf("%d is a prime number\n", number);
    return 0;
}