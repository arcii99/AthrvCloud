//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* function prototypes */
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double root(double);
int fact(int);

int main() {
    /* variable declaration */
    char operator;
    double num1, num2, result;

    /* get input */
    printf("Enter an operator (+, -, *, /, ^, r, !): ");
    scanf("%c", &operator);

    /* check which operation to perform */
    switch(operator) {
        case '+': /* addition */
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = add(num1, num2);
            printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
            break;

        case '-': /* subtraction */
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = subtract(num1, num2);
            printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
            break;

        case '*': /* multiplication */
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = multiply(num1, num2);
            printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
            break;

        case '/': /* division */
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if(num2 == 0) {
                printf("Error: Division by zero");
            } else {
                result = divide(num1, num2);
                printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
            }
            break;

        case '^': /* power */
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = power(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
            break;

        case 'r': /* root */
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = root(num1);
            printf("sqrt(%.2lf) = %.2lf", num1, result);
            break;

        case '!': /* factorial */
            printf("Enter a positive integer: ");
            scanf("%lf", &num1);
            if(num1 < 0) {
                printf("Error: Cannot find factorial of negative number");
            } else if(num1 > (int)num1) {
                printf("Error: Cannot find factorial of non-integer number");
            } else {
                result = (double)fact((int)num1);
                printf("%.0lf! = %.0lf", num1, result);
            }
            break;

        default: /* invalid operator */
            printf("Error: Invalid operator");
    }

    return 0;
}

/* function definition for addition */
double add(double x, double y) {
    return x + y;
}

/* function definition for subtraction */
double subtract(double x, double y) {
    return x - y;
}

/* function definition for multiplication */
double multiply(double x, double y) {
    return x * y;
}

/* function definition for division */
double divide(double x, double y) {
    return x / y;
}

/* function definition for power */
double power(double x, double y) {
    return pow(x, y);
}

/* function definition for root */
double root(double x) {
    return sqrt(x);
}

/* function definition for factorial */
int fact(int x) {
    int result = 1;
    for(int i = 2; i <= x; i++) {
        result *= i;
    }
    return result;
}