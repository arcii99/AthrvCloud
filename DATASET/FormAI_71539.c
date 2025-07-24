//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

// define the operations on the calculator
#define ADDITION '+'
#define SUBTRACTION '-'
#define MULTIPLICATION '*'
#define DIVISION '/'
#define POWER '^'
#define SQUARE_ROOT 's'

int main() {
    float num1, num2, result;
    char operation;

    printf("\nWelcome to Ken Thompson's Calculator!\n\n");

    printf("Please enter the first number: ");
    scanf("%f", &num1);

    printf("\nPlease enter the operation you would like to perform\n");
    printf("Addition:       +\n");
    printf("Subtraction:    -\n");
    printf("Multiplication: *\n");
    printf("Division:       /\n");
    printf("Power:          ^\n");
    printf("Square Root:    s\n\n");

    printf("Operation:  ");
    scanf(" %c", &operation);

    // make sure the user enters a valid operation
    while (operation != ADDITION && operation != SUBTRACTION && operation != MULTIPLICATION 
           && operation != DIVISION && operation != POWER && operation != SQUARE_ROOT) {
        printf("\nInvalid operation. Please enter a valid operation: ");
        scanf(" %c", &operation);
    }

    switch (operation) {
        case ADDITION:
            printf("\nPlease enter the second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
            break;

        case SUBTRACTION:
            printf("\nPlease enter the second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
            break;

        case MULTIPLICATION:
            printf("\nPlease enter the second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("\n%.2f * %.2f = %.2f\n", num1, num2, result);
            break;

        case DIVISION:
            printf("\nPlease enter the second number: ");
            scanf("%f", &num2);
            // make sure the user does not divide by zero
            while (num2 == 0) {
                printf("\nCannot divide by zero. Please enter a valid second number: ");
                scanf("%f", &num2);
            }
            result = num1 / num2;
            printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
            break;

        case POWER:
            printf("\nPlease enter the power: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("\n%.2f ^ %.2f = %.2f\n", num1, num2, result);
            break;

        case SQUARE_ROOT:
            result = sqrt(num1);
            printf("\nSquare root of %.2f = %.2f\n", num1, result);
            break;

        default:
            printf("\nInvalid operation. Please try again.\n");
    }

    printf("\nThank you for using Ken Thompson's Calculator!\n");

    return 0;
}