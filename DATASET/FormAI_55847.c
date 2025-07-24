//FormAI DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int num1, num2, num3;
    char op1, op2;
    int result, answer;
    srand(time(NULL));

    // Generate first operand, operator and second operand
    num1 = rand() % 100;
    num2 = rand() % 100;
    num3 = rand() % 100;
    op1 = (rand() % 2 == 0) ? '+' : '-';
    op2 = (rand() % 2 == 0) ? '*' : '/';

    // Calculate the result based on the generated operands and operators
    printf("What is the value of: %d %c %d %c %d ?\n", num1, op1, num2, op2, num3);
    if (op1 == '+')
    {
        if (op2 == '*')
            result = num1 + num2 * num3;
        else
            result = num1 + num2 / num3;
    }
    else
    {
        if (op2 == '*')
            result = num1 - num2 * num3;
        else
            result = num1 - num2 / num3;
    }

    // Get the answer from the user and check if it's correct
    printf("Answer: ");
    scanf("%d", &answer);

    if (answer == result)
        printf("Correct!\n");
    else
        printf("Incorrect, the answer is: %d\n", result);

    return 0;
}