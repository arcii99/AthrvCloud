//FormAI DATASET v1.0 Category: Syntax parsing ; Style: grateful
#include <stdio.h>

int main()
{
    char input[20];
    int operand1 = 0, operand2 = 0, result = 0;
    char operator;

    printf("Enter a mathematical expression (ex. 5 + 2):");
    fgets(input, 20, stdin);

    sscanf(input, "%d %c %d", &operand1, &operator, &operand2);

    switch (operator)
    {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case '*':
        result = operand1 * operand2;
        break;
    case '/':
        if (operand2 == 0)
        {
            printf("Error: Cannot divide by zero");
            return 1;
        }
        else
        {
            result = operand1 / operand2;
        }
        break;
    default:
        printf("Error: Invalid operator");
        return 1;
    }

    printf("%d %c %d = %d", operand1, operator, operand2, result);

    return 0;
}