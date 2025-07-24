//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double calculate(char *input) {
    double num1, num2, result;
    char operator;

    sscanf(input, "%lf%c%lf", &num1, &operator, &num2);

    switch(operator) {
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
        case '^':
            result = pow(num1, num2);
            break;
        case 's':
            result = sin(num1);
            break;
        case 'c':
            result = cos(num1);
            break;
        case 't':
            result = tan(num1);
            break;
        case 'l':
            result = log(num1);
            break;
        default:
            printf("Invalid operator");
            return 0;
    }

    return result;
}

int main() {
    char input[50];

    printf("Enter a calculation: ");
    fgets(input, 50, stdin);

    double result = calculate(input);

    printf("Result = %lf", result);

    return 0;
}