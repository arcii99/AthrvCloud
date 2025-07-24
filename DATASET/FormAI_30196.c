//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num1, num2, op, result;
    float num3, num4, fResult;
    // Introduction
    printf("Welcome to the Math Exercise Program!\n");

    // Main Menu
    printf("Please select an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Square Root\n");
    printf("6. Power\n");
    scanf("%d", &op);

    switch(op) {
        // Addition
        case 1:
            printf("Enter two numbers to add:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            printf("%d + %d = %d\n", num1, num2, result);
            break;

        // Subtraction
        case 2:
            printf("Enter two numbers to subtract:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, result);
            break;

        // Multiplication
        case 3:
            printf("Enter two numbers to multiply:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            printf("%d x %d = %d\n", num1, num2, result);
            break;

        // Division
        case 4:
            printf("Enter two numbers to divide:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 / num2;
            printf("%d / %d = %d\n", num1, num2, result);
            break;

        // Square root
        case 5:
            printf("Enter a number to find its square root:\n");
            scanf("%f", &num3);
            fResult = sqrt(num3);
            printf("The square root of %.2f is %.2f\n", num3, fResult);
            break;

        // Power
        case 6:
            printf("Enter a base number:\n");
            scanf("%f", &num3);
            printf("Enter an exponent:\n");
            scanf("%f", &num4);
            fResult = pow(num3, num4);
            printf("%.2f to the power of %.2f is %.2f\n", num3, num4, fResult);
            break;

        // Invalid Input
        default:
            printf("Invalid input. Please enter a number from 1 to 6.\n");
            break;
    }
    return 0;
}