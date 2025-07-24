//FormAI DATASET v1.0 Category: Calculator ; Style: funny
#include<stdio.h>

void main()
{
    int num1, num2, result;
    char operator;
    
    printf("Welcome to the Funny Calculator!\n");
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    
    printf("Please enter the second number: ");
    scanf("%d", &num2);
    
    printf("Please choose an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    
    switch (operator)
    {
        case '+':
            result = num1 + num2;
            printf("The sum is: %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("The difference is: %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("The product is: %d\n", result);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Oops! Division by zero not allowed.\n");
            }
            else
            {
                result = num1 / num2;
                printf("The quotient is: %d\n", result);
            }
            break;
        default:
            printf("Invalid operator entered. Try again!\n");
            break;
    }
    
    printf("Thank you for using the Funny Calculator! Come again soon!\n");
}