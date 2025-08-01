//FormAI DATASET v1.0 Category: Calculator ; Style: imaginative
#include <stdio.h>

int main()
{
    printf("+------------------------------------------------+\n");
    printf("|              CALCULATOR by Bot                 |\n");
    printf("+------------------------------------------------+\n");

    int choice;
    float num1, num2, result;

    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    switch (choice)
    {
    case 1:
        result = num1 + num2;
        printf("Result: %.2f", result);
        break;

    case 2:
        result = num1 - num2;
        printf("Result: %.2f", result);
        break;

    case 3:
        result = num1 * num2;
        printf("Result: %.2f", result);
        break;

    case 4:
        if (num2 == 0)
        {
            printf("Error! Cannot divide by zero.");
        }
        else
        {
            result = num1 / num2;
            printf("Result: %.2f", result);
        }
        break;

    default:
        printf("Invalid choice. Please choose again.");
    }

    printf("\n+------------------------------------------------+\n");

    return 0;
}