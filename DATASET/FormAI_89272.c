//FormAI DATASET v1.0 Category: Calculator ; Style: sophisticated
// A sophisticated calculator program in C language

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice;
    double num1, num2, result;

    // Display the menu to the user
    printf("Welcome to the Sophisticated Calculator Program!\n");
    printf("Please enter the number of the operation you would like to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Power\n");

    // Get the user's choice
    scanf("%d", &choice);

    switch (choice)
    {
        case 1: // Addition
            printf("Please enter the first number: ");
            scanf("%lf", &num1);
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("The result is %.2lf\n", result);
            break;

        case 2: // Subtraction
            printf("Please enter the first number: ");
            scanf("%lf", &num1);
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("The result is %.2lf\n", result);
            break;

        case 3: // Multiplication
            printf("Please enter the first number: ");
            scanf("%lf", &num1);
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("The result is %.2lf\n", result);
            break;

        case 4: // Division
            printf("Please enter the first number: ");
            scanf("%lf", &num1);
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            if (num2 == 0)
            {
                printf("Error: Division by zero is not allowed\n");
            }
            else
            {
                result = num1 / num2;
                printf("The result is %.2lf\n", result);
            }
            break;

        case 5: // Square Root
            printf("Please enter the number: ");
            scanf("%lf", &num1);
            if (num1 < 0)
            {
                printf("Error: Cannot calculate the square root of a negative number\n");
            }
            else
            {
                result = sqrt(num1);
                printf("The result is %.2lf\n", result);
            }
            break;

        case 6: // Power
            printf("Please enter the base: ");
            scanf("%lf", &num1);
            printf("Please enter the exponent: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("The result is %.2lf\n", result);
            break;

        default:
            printf("Error: Invalid choice\n");
            break;
    }

    return 0;
}