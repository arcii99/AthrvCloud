//FormAI DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>

int main() {
    int num1, num2;
    double result;

    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    // Addition
    result = (double)num1 + num2;
    printf("Addition: %d + %d = %.2f\n", num1, num2, result);

    // Subtraction
    result = (double)num1 - num2;
    printf("Subtraction: %d - %d = %.2f\n", num1, num2, result);

    // Multiplication
    result = (double)num1 * num2;
    printf("Multiplication: %d * %d = %.2f\n", num1, num2, result);

    // Division
    if(num2 != 0) {
        result = (double)num1 / num2;
        printf("Division: %d / %d = %.2f\n", num1, num2, result);
    } else {
        printf("Cannot divide by zero.\n");
    }
    
    // Modulus
    if(num2 != 0) {
        result = num1 % num2;
        printf("Modulus: %d %% %d = %.2f\n", num1, num2, result);
    } else {
        printf("Cannot perform modulus operation with zero.\n");
    }

    return 0;
}