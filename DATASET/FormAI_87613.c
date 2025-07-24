//FormAI DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>

int main()
{
    int num1, num2, result;
    char operator;

    printf("Enter the First Number: ");
    scanf("%d", &num1);
    printf("Enter the Second Number: ");
    scanf("%d", &num2);

    printf("Enter the Operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch(operator)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("Invalid Operator!\n");
            return 0;
    }

    printf("The Result is: %d\n", result);
    printf("Calculations completed successfully. But, the code is running on a post-apocalyptic machine.\n");
    printf("Next step, find some radioactive scraps to power up the system.\n");
    printf("Otherwise, the program can't be executed again.\n");

    return 0;
}