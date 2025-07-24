//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

/* define an error code for division by zero */
#define DIVIDE_BY_ZERO_ERROR 111

/* function to divide two numbers */
double divide(double a, double b) {
    if (b == 0) {
        /* if divisor is zero, throw an error */
        exit(DIVIDE_BY_ZERO_ERROR);
    } else {
        return a / b;
    }
}

int main() {
    double num1, num2, result;
    printf("Enter numerator: ");
    scanf("%lf", &num1);
    printf("Enter divisor: ");
    scanf("%lf", &num2);
    result = divide(num1, num2);
    if (result == DIVIDE_BY_ZERO_ERROR) {
        /* handle divide by zero error */
        printf("Error: Division by zero detected.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Result: %lf\n", result);
    }
    return 0;
}