//FormAI DATASET v1.0 Category: Arithmetic ; Style: future-proof
#include <stdio.h>

int main() {
    // Get two numbers from user input
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Perform arithmetic operations
    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    int quotient = num1 / num2;
    int remainder = num1 % num2;

    // Display results
    printf("\nArithmetic results:\n");
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);

    // Future-proofing: add support for floating-point operations
    float fnum1 = num1;
    float fnum2 = num2;
    float fsum = fnum1 + fnum2;
    float fdifference = fnum1 - fnum2;
    float fproduct = fnum1 * fnum2;
    float fquotient = fnum1 / fnum2;

    // Display floating-point results
    printf("\nFloating-point results:\n");
    printf("Sum: %f\n", fsum);
    printf("Difference: %f\n", fdifference);
    printf("Product: %f\n", fproduct);
    printf("Quotient: %f\n", fquotient);

    return 0;
}