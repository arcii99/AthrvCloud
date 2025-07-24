//FormAI DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a given number
int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int main()
{
    int num1, num2, result;
    char operator;

    printf("Enter an arithmetic expression in the following format:\n");
    printf("num1 operator num2\n");

    scanf("%d %c %d", &num1, &operator, &num2);

    switch(operator)
    {
        case '+':
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Error: division by zero!\n");
                exit(0);
            }
            result = num1 / num2;
            printf("Result: %d\n", result);
            break;
        case '%':
            if (num2 == 0)
            {
                printf("Error: Modulo by zero!\n");
                exit(0);
            }
            result = num1 % num2;
            printf("Result: %d\n", result);
            break;
        case '^':
            result = pow(num1, num2);
            printf("Result: %d\n", result);
            break;
        case '!':
            if (num1 < 0)
            {
                printf("Error: Factorial of negative number is undefined!\n");
                exit(0);
            }
            result = factorial(num1);
            printf("Result: %d\n", result);
            break;
        default:
            printf("Error: Invalid operator.\n");
            exit(0);
    }

    return 0;
}