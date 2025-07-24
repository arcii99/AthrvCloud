//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <math.h>

int main()
{
    int choice, num1, num2;
    float result;

    printf("\nSCIENTIFIC CALCULATOR\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter the first number: ");
            scanf("%d", &num1);
            printf("\nEnter the second number: ");
            scanf("%d", &num2);
            result = num1 + num2;
            printf("\n%d + %d = %.2f\n", num1, num2, result);
            break;

        case 2:
            printf("\nEnter the first number: ");
            scanf("%d", &num1);
            printf("\nEnter the second number: ");
            scanf("%d", &num2);
            result = num1 - num2;
            printf("\n%d - %d = %.2f\n", num1, num2, result);
            break;

        case 3:
            printf("\nEnter the first number: ");
            scanf("%d", &num1);
            printf("\nEnter the second number: ");
            scanf("%d", &num2);
            result = num1 * num2;
            printf("\n%d * %d = %.2f\n", num1, num2, result);
            break;

        case 4:
            printf("\nEnter the first number: ");
            scanf("%d", &num1);
            printf("\nEnter the second number: ");
            scanf("%d", &num2);
            if (num2 != 0)
            {
                result = (float)num1 / num2;
                printf("\n%d / %d = %.2f\n", num1, num2, result);
            }
            else
            {
                printf("\nCannot divide by zero.\n");
            }
            break;

        case 5:
            printf("\nEnter the base number: ");
            scanf("%d", &num1);
            printf("\nEnter the exponent number: ");
            scanf("%d", &num2);
            result = pow(num1, num2);
            printf("\n%d ^ %d = %.2f\n", num1, num2, result);
            break;

        case 6:
            printf("\nEnter the number to find its square root: ");
            scanf("%d", &num1);
            if (num1 >= 0)
            {
                result = sqrt(num1);
                printf("\nSquare root of %d = %.2f\n", num1, result);
            }
            else
            {
                printf("\nInvalid input. Cannot find square root of negative numbers.\n");
            }
            break;

        default:
            printf("\nInvalid choice. Please select a number between 1 and 6.\n");
            break;
    }

    return 0;
}