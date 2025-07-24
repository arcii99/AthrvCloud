//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice, cont = 1;
    double num1, num2, result;

    while (cont == 1)
    {
        printf("\n---SCIENTIFIC CALCULATOR---\n");
        printf("\nOperations Available:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square Root\n");
        printf("6. Power Function\n");
        printf("7. Logaritmic Function (Base-10)\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("Result: %lf\n", result);
            break;

        case 2:
            printf("\nEnter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("Result: %lf\n", result);
            break;

        case 3:
            printf("\nEnter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("Result: %lf\n", result);
            break;

        case 4:
            printf("\nEnter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 == 0)
            {
                printf("Error: Division by zero is not possible\n");
            }
            else
            {
                result = num1 / num2;
                printf("Result: %lf\n", result);
            }
            break;

        case 5:
            printf("\nEnter a number to calculate its square root: ");
            scanf("%lf", &num1);
            if (num1 < 0)
            {
                printf("Error: Square root of negative numbers is not possible\n");
            }
            else
            {
                result = sqrt(num1);
                printf("Result: %lf\n", result);
            }
            break;

        case 6:
            printf("\nEnter a number and its exponent: ");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("Result: %lf\n", result);
            break;

        case 7:
            printf("\nEnter a number to calculate its logarithm (Base-10): ");
            scanf("%lf", &num1);
            if (num1 <= 0)
            {
                printf("Error: Logarithm of non-positive numbers is not possible\n");
            }
            else
            {
                result = log10(num1);
                printf("Result: %lf\n", result);
            }
            break;

        case 8:
            cont = 0;
            break;

        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
        }
    }

    printf("\n---THANK YOU! PROGRAM TERMINATED---\n");

    return 0;
}