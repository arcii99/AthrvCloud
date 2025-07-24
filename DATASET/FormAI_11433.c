//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    double num1, num2, result;
    char op;

    do
    {
        printf("\nWelcome to Scientific Calculator");
        printf("\n1. Addition (+)");
        printf("\n2. Subtraction (-)");
        printf("\n3. Multiplication (*)");
        printf("\n4. Division (/)");
        printf("\n5. Power (^)");
        printf("\n6. Square root");
        printf("\n7. Logarithm (base 10)");
        printf("\n8. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0)
                {
                    printf("Error: Division undefined\n");
                }
                else
                {
                    result = num1 / num2;
                    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
            case 5:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 6:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                if (num1 < 0)
                {
                    printf("Error: Square root of negative number is not defined\n");
                }
                else
                {
                    result = sqrt(num1);
                    printf("Sqrt(%.2lf) = %.2lf\n", num1, result);
                }
                break;
            case 7:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                if (num1 <= 0)
                {
                    printf("Error: Logarithm of non-positive number is not defined\n");
                }
                else
                {
                    result = log10(num1);
                    printf("Log(%.2lf) = %.2lf\n", num1, result);
                }
                break;
            case 8:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice");
        }

    } while (choice != 8);

    return 0;
}