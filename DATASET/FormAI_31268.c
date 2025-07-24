//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define PI 3.14159265358979323846
#define E 2.71828182845904523536

void clear_input_buffer();
int check_valid_input(char input[]);
double calculate(char operation[], double num1, double num2);

int main()
{
    char input[100];
    double num1, num2, result;
    int valid_input;

    do
    {
        printf("\nWelcome to Paranoid Scientific Calculator!\n");
        printf("Enter an operation (e.g. +, -, *, /, sin, cos, tan, sqrt, log, pi, e)\n");
        printf("Enter 'q' to quit.\n\n");
        printf("Operation: ");
        fgets(input, 100, stdin);
        clear_input_buffer();

        if (strcmp(input, "q\n") == 0)
        {
            printf("\nExiting Paranoid Scientific Calculator...\n");
            break;
        }

        valid_input = check_valid_input(input);

        if (!valid_input)
        {
            printf("\nError: Invalid input.\n");
            continue;
        }

        if (strcmp(input, "pi\n") == 0)
        {
            result = PI;
            printf("\nResult: %lf\n", result);
        }

        else if (strcmp(input, "e\n") == 0)
        {
            result = E;
            printf("\nResult: %lf\n", result);
        }

        else if (strcmp(input, "sqrt\n") == 0)
        {
            printf("\nEnter a number: ");
            scanf("%lf", &num1);
            clear_input_buffer();

            if (num1 < 0)
            {
                printf("\nError: Square root of negative number is undefined.\n");
                continue;
            }

            result = sqrt(num1);
            printf("\nResult: %lf\n", result);
        }

        else if (strcmp(input, "log\n") == 0)
        {
            printf("\nEnter a number: ");
            scanf("%lf", &num1);
            clear_input_buffer();

            if (num1 < 0)
            {
                printf("\nError: Logarithm of negative number is undefined.\n");
                continue;
            }

            result = log(num1);
            printf("\nResult: %lf\n", result);
        }

        else
        {
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            clear_input_buffer();

            result = calculate(input, num1, num2);
            printf("\nResult: %lf\n", result);
        }

    } while (1);

    return 0;
}

void clear_input_buffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int check_valid_input(char input[])
{
    int i;

    for (i = 0; input[i] != '\n'; i++)
    {
        if (isalpha(input[i]) && input[i] != 'p' && input[i] != 'i' && input[i] != 'e')
            return 0;

        if (isspace(input[i]))
            continue;

        if (!isdigit(input[i]) && input[i] != '.' && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != 's' && input[i] != 'c' && input[i] != 't' && input[i] != 'q' && input[i] != 'r' && input[i] != 'l')
            return 0;
    }

    return 1;
}

double calculate(char operation[], double num1, double num2)
{
    double result;

    if (strcmp(operation, "+") == 0)
        result = num1 + num2;

    else if (strcmp(operation, "-") == 0)
        result = num1 - num2;

    else if (strcmp(operation, "*") == 0)
        result = num1 * num2;

    else if (strcmp(operation, "/") == 0)
    {
        if (num2 == 0)
        {
            printf("\nError: Division by zero is undefined.\n");
            return 0;
        }

        result = num1 / num2;
    }

    else if (strcmp(operation, "sin") == 0)
        result = sin(num1);

    else if (strcmp(operation, "cos") == 0)
        result = cos(num1);

    else if (strcmp(operation, "tan") == 0)
        result = tan(num1);

    return result;
}