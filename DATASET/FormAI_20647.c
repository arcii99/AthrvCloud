//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int choice;
    double num1, num2, result;

    while (1) {
        printf("\nEnter 1 for Addition");
        printf("\nEnter 2 for Subtraction");
        printf("\nEnter 3 for Multiplication");
        printf("\nEnter 4 for Division");
        printf("\nEnter 5 for Square root");
        printf("\nEnter 6 for Power calculation");
        printf("\nEnter 7 for Modulo operation");
        printf("\nEnter 0 to Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Addition
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("\nResult: %lf\n", result);
                break;

            case 2: // Subtraction
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("\nResult: %lf\n", result);
                break;

            case 3: // Multiplication
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("\nResult: %lf\n", result);
                break;

            case 4: // Division
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                if (num2 == 0) {
                    printf("\nCannot divide by zero!\n");
                    break;
                }
                result = num1 / num2;
                printf("\nResult: %lf\n", result);
                break;

            case 5: // Square root
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                result = sqrt(num1);
                printf("\nResult: %lf\n", result);
                break;

            case 6: // Power calculation
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                printf("Enter the power: ");
                scanf("%lf", &num2);
                result = pow(num1, num2);
                printf("\nResult: %lf\n", result);
                break;

            case 7: // Modulo operation
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = fmod(num1, num2);
                printf("\nResult: %lf\n", result);

            case 0: // Quit
                printf("\nThank you for using the calculator!\n");
                exit(0);
            
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}