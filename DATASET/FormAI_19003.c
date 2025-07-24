//FormAI DATASET v1.0 Category: Calculator ; Style: energetic
#include <stdio.h>

int main()
{
    int num1, num2, result;
    char operator;

    printf("Welcome to the Energetic Calculator!\n");

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter second number: ");
    scanf("%d", &num2);

    switch (operator)
    {
        case '+':
            result = num1 + num2;
            printf("The result of %d + %d is: %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("The result of %d - %d is: %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("The result of %d * %d is: %d\n", num1, num2, result);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Error: Cannot divide by zero!\n");
            }
            else
            {
                result = num1 / num2;
                printf("The result of %d / %d is: %d\n", num1, num2, result);
            }
            break;
        default:
            printf("Invalid operator entered!\n");
    }

    printf("Thank you for using the Energetic Calculator! Have a great day!\n");

    return 0;
}