//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double modulo(double, double);
double power(double, double);
double square_root(double);
double absolute_value(double);

int main()
{
    // Variable declarations
    char operator;
    double num1, num2, result;

    // Displaying calculator options
    printf("--- C Scientific Calculator Implementation ---\n\n");
    printf("Please select an operation:\n");
    printf("+ Addition\n");
    printf("- Subtraction\n");
    printf("* Multiplication\n");
    printf("/ Division\n");
    printf("%% Modulo\n");
    printf("^ Power\n");
    printf("s Square root\n");
    printf("|x| Absolute value\n");

    // Reading user choice and numbers
    printf("\nEnter operator: ");
    scanf("%c", &operator);
    printf("Enter first number: ");
    scanf("%lf", &num1);
    if (operator != 's' && operator != '|') {
        printf("Enter second number: ");
        scanf("%lf", &num2);
    }

    // Performing calculation based on operator
    switch(operator)
    {
        case '+':
            result = add(num1, num2);
            break;

        case '-':
            result = subtract(num1, num2);
            break;

        case '*':
            result = multiply(num1, num2);
            break;

        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
            result = divide(num1, num2);
            break;

        case '%':
            result = modulo(num1, num2);
            break;

        case '^':
            result = power(num1, num2);
            break;

        case 's':
            result = square_root(num1);
            break;

        case '|':
            result = absolute_value(num1);
            break;

        default:
            printf("Error: Invalid operator.\n");
            exit(EXIT_FAILURE);
    }

    // Displaying result
    printf("Result: %lf\n", result);

    return 0;
}

// Addition function
double add(double num1, double num2)
{
    return num1 + num2;
}

// Subtraction function
double subtract(double num1, double num2)
{
    return num1 - num2;
}

// Multiplication function
double multiply(double num1, double num2)
{
    return num1 * num2;
}

// Division function
double divide(double num1, double num2)
{
    return num1 / num2;
}

// Modulo function
double modulo(double num1, double num2)
{
    return fmod(num1, num2);
}

// Power function
double power(double num1, double num2)
{
    return pow(num1, num2);
}

// Square root function
double square_root(double num1)
{
    return sqrt(num1);
}

// Absolute value function
double absolute_value(double num1)
{
    return fabs(num1);
}