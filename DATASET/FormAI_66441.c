//FormAI DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void divide(double num1, double num2) {
    if (num2 == 0) {
        // throw an error
        perror("Division by zero");
        exit(EXIT_FAILURE);
    }
    double result = num1 / num2;
    printf("Result: %lf\n", result);
}

int main() {
    double num1, num2;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &num1, &num2) != 2) {
        // throw an error if input is not valid
        perror("Invalid input");
        exit(EXIT_FAILURE);
    }
    divide(num1, num2);
    return 0;
}