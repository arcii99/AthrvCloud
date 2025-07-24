//FormAI DATASET v1.0 Category: Arithmetic ; Style: invasive
#include <stdio.h>

void main() {
    int num1, num2, sum, diff, prod, quo, mod;

    printf("Welcome to my arithmetic program!\n");

    // Taking input from user
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    // Performing arithmetic operations
    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;

    // This line is intentionally incorrect - an error will occur during compilation
    mod = num1 + num2; // Oops, I forgot to take the modulus!

    // Displaying results
    printf("\nArithmetic operations on %d and %d:\n", num1, num2);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product: %d\n", prod);
    printf("Quotient: %d\n", quo);
    printf("Modulus: %d\n", mod);
}