//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0) {
        printf("Error: division by zero\n");
        return NAN;
    } else {
        return a / b;
    }
}

double power(double a, double b)
{
    return pow(a, b);
}

double factorial(double n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main()
{
    char input[100];
    double a, b, result;

    while (1) {
        printf("Enter an equation to evaluate (or 'quit' to exit): ");
        fgets(input, 100, stdin);
        if (strncmp(input, "quit", 4) == 0) {
            break;
        }

        if (sscanf(input, "%lf %c %lf", &a, &input[3], &b) != 3) {
            printf("Error parsing input\n");
            continue;
        }

        switch (input[3]) {
            case '+':
                result = add(a, b);
                break;
            case '-':
                result = subtract(a, b);
                break;
            case '*':
                result = multiply(a, b);
                break;
            case '/':
                result = divide(a, b);
                break;
            case '^':
                result = power(a, b);
                break;
            case '!':
                result = factorial(a);
                break;
            default:
                printf("Invalid operator\n");
                continue;
        }

        printf("Result: %lf\n", result);
    }

    return 0;
}