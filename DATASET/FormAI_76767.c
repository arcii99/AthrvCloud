//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: authentic
#include <stdio.h>
#include <math.h>

void printOptions()
{
    printf("\n\n");
    printf("Enter the number corresponding to the operation you want to do:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power function\n");
    printf("6. Square root function\n");
    printf("7. Logarithmic function\n");
    printf("8. Exponential function\n");
    printf("9. Trigonometric function\n");
    printf("0. Exit\n");
    printf("Option: ");
}

int main()
{
    int option;
    double num1, num2, result;

    printf("Welcome to Scientific Calculator v1.0");

    do
    {
        printOptions();
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("\nResult: %lf\n", result);
                break;

            case 2:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("\nResult: %lf\n", result);
                break;

            case 3:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("\nResult: %lf\n", result);
                break;

            case 4:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 / num2;
                printf("\nResult: %lf\n", result);
                break;

            case 5:
                printf("\nEnter base: ");
                scanf("%lf", &num1);
                printf("Enter exponent: ");
                scanf("%lf", &num2);
                result = pow(num1, num2);
                printf("\nResult: %lf\n", result);
                break;

            case 6:
                printf("\nEnter number: ");
                scanf("%lf", &num1);
                result = sqrt(num1);
                printf("\nResult: %lf\n", result);
                break;

            case 7:
                printf("\nEnter number: ");
                scanf("%lf", &num1);
                result = log(num1);
                printf("\nResult: %lf\n", result);
                break;

            case 8:
                printf("\nEnter number: ");
                scanf("%lf", &num1);
                result = exp(num1);
                printf("\nResult: %lf\n", result);
                break;

            case 9:
                printf("\nEnter angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * 3.14159 / 180.0);
                printf("\nSine is: %lf", result);
                result = cos(num1 * 3.14159 / 180.0);
                printf("\nCosine is: %lf", result);
                result = tan(num1 * 3.14159 / 180.0);
                printf("\nTangent is: %lf\n", result);
                break;

            case 0:
                printf("\nGoodbye!");
                break;

            default:
                printf("\nInvalid option! Please select a valid option.\n");
        }
    } while(option != 0);

    return 0;
}