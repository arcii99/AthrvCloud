//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genious
#include <stdio.h>
#include <math.h>

/* Function to add two numbers */
double add(double x, double y) {
    return x + y;
}

/* Function to subtract two numbers */
double subtract(double x, double y) {
    return x - y;
}

/* Function to multiply two numbers */
double multiply(double x, double y) {
    return x * y;
}

/* Function to divide two numbers */
double divide(double x, double y) {
    if (y == 0) {
        printf("Error: Division by zero\n");
        return NAN;
    } else {
        return x / y;
    }
}

/* Function to calculate the factorial of a number */
double factorial(double x) {
    if (x < 0) {
        printf("Error: Factorial of a negative number is undefined\n");
        return NAN;
    } else if (x == 0) {
        return 1;
    } else {
        return x * factorial(x - 1);
    }
}

/* Function to calculate n choose r */
double choose(double n, double r) {
    if (n < r) {
        printf("Error: n must be greater than or equal to r\n");
        return NAN;
    } else {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }
}

/* Main function */
int main() {
    double num1, num2, result;
    char operator;

    printf("Enter a mathematical expression: ");
    scanf("%lf %c %lf", &num1, &operator, &num2);

    switch (operator) {
        case '+':
            result = add(num1, num2);
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            result = divide(num1, num2);
            if (!isnan(result)) {
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;
        case '^':
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '!':
            result = factorial(num1);
            if (!isnan(result)) {
                printf("%.2lf! = %.2lf\n", num1, result);
            }
            break;
        case 'C':
            result = choose(num1, num2);
            if (!isnan(result)) {
                printf("%.2lf choose %.2lf = %.2lf\n", num1, num2, result);
            }
            break;
        default:
            printf("Error: Invalid operator\n");
            break;
    }

    return 0;
}