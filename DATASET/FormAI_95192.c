//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 50

double calculate(double val1, double val2, char op);

int main() {
    char input[MAX_LEN];
    double num1, num2, result;
    char operator;
    int i;

    printf("Welcome to the C Scientific Calculator!\n");
    printf("Enter your calculation below:\n");
    fgets(input, MAX_LEN, stdin);

    // Remove newline character from input
    for (i = 0; i < MAX_LEN; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    // Parse values and operator from input
    sscanf(input, "%lf %c %lf", &num1, &operator, &num2);

    // Calculate result
    result = calculate(num1, num2, operator);

    // Print result
    printf("Result: %lf\n", result);

    return 0;
}

double calculate(double val1, double val2, char op) {
    double result;
    switch(op) {
        case '+':
            result = val1 + val2;
            break;
        case '-':
            result = val1 - val2;
            break;
        case '*':
            result = val1 * val2;
            break;
        case '/':
            if (val2 == 0) {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            result = val1 / val2;
            break;
        case '^':
            result = pow(val1, val2);
            break;
        case '%':
            result = fmod(val1, val2);
            break;
        case 's':
            result = sin(val1);
            break;
        case 'c':
            result = cos(val1);
            break;
        case 't':
            result = tan(val1);
            break;
        default:
            printf("Error: Invalid operator\n");
            exit(EXIT_FAILURE);
    }

    return result;
}