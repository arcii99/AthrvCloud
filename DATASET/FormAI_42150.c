//FormAI DATASET v1.0 Category: Educational ; Style: surprised
#include<stdio.h>

int main()
{
    printf("Wow! I can't believe I actually wrote a program in C!\n");
    printf("I never thought I'd be able to create something like this.\n");
    printf("For my first program, I think I'll make a calculator. Ready?\n\n");

    int num1, num2;
    char operator;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    int result;
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
            printf("Whoa, that's not a valid operator! Try again.\n");
            return 0;
    }

    printf("\nThe result is: %d\n\n", result);
    printf("Oh my, I'm so surprised that it actually works! I never thought I could do something like this in C. But I did it! Hooray!");

    return 0;
}