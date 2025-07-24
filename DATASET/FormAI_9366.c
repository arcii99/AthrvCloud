//FormAI DATASET v1.0 Category: Scientific ; Style: creative
#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if number is positive or negative
    if (num > 0) {
        printf("%d is a positive number.\n", num);

        // Check if number is even or odd
        if (num % 2 == 0) {
            printf("%d is an even number.", num);
        } else {
            printf("%d is an odd number.", num);
        }
    } else {
        printf("%d is a negative number.", num);
    }

    // Calculate the factorial of the entered number
    int factorial = 1;
    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }
    printf("\nFactorial of %d is %d.", num, factorial);

    // Print the Fibonacci series up to the entered number
    int a = 0, b = 1, c;
    printf("\nFibonacci series up to %d: %d, %d, ", num, a, b);
    for (int i = 0; i < num; i++) {
        c = a + b;
        a = b;
        b = c;
        if (c <= num) {
            printf("%d, ", c);
        } else {
            break;
        }
    }

    return 0;
}