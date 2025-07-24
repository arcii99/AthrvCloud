//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Welcome to my Scientific Calculator Implementation!\n");
    printf("Enter the operation you want to perform from the following:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square root\n");

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > 6)
    {
        printf("Invalid choice, please choose a number between 1 and 6.\n");
    }
    else
    {
        double num1, num2, result;

        switch (choice)
        {
            case 1:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("The result is: %lf\n", result);
                break;

            case 2:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("The result is: %lf\n", result);
                break;

            case 3:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("The result is: %lf\n", result);
                break;

            case 4:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                if (num2 == 0)
                {
                    printf("Cannot divide by zero.\n");
                }
                else
                {
                    result = num1 / num2;
                    printf("The result is: %lf\n", result);
                }
                break;

            case 5:
                printf("Enter the base number: ");
                scanf("%lf", &num1);
                printf("Enter the exponent number: ");
                scanf("%lf", &num2);
                result = pow(num1, num2);
                printf("The result is: %lf\n", result);
                break;

            case 6:
                printf("Enter the number: ");
                scanf("%lf", &num1);
                if (num1 < 0)
                {
                    printf("Cannot calculate square root of a negative number.\n");
                }
                else
                {
                    result = sqrt(num1);
                    printf("The result is: %lf\n", result);
                }
                break;

            default:
                break;
        }
    }

    return 0;
}