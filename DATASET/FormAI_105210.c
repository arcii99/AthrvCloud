//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <math.h>

double getInput(char message[]);
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double sqrt_func(double a);
double log_func(double a);
double sin_func(double a);
double cos_func(double a);
double tan_func(double a);

int main() {
    double num1, num2, result;
    int operation;
    printf("Welcome to the C Scientific Calculator!\n");
    printf("Please choose an operation:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power\n6. Square Root\n7. Natural Logarithm\n8. Sine\n9. Cosine\n10. Tangent\n");
    scanf("%d", &operation);
    switch(operation) {
        case 1:
            num1 = getInput("Please enter the first number: ");
            num2 = getInput("Please enter the second number: ");
            result = add(num1, num2);
            printf("The sum of %.2lf and %.2lf is %.2lf.", num1, num2, result);
            break;
        case 2:
            num1 = getInput("Please enter the first number: ");
            num2 = getInput("Please enter the second number: ");
            result = subtract(num1, num2);
            printf("%.2lf minus %.2lf is %.2lf.", num1, num2, result);
            break;
        case 3:
            num1 = getInput("Please enter the first number: ");
            num2 = getInput("Please enter the second number: ");
            result = multiply(num1, num2);
            printf("%.2lf multiplied by %.2lf is %.2lf.", num1, num2, result);
            break;
        case 4:
            num1 = getInput("Please enter the first number: ");
            num2 = getInput("Please enter the second number: ");
            result = divide(num1, num2);
            printf("%.2lf divided by %.2lf is %.2lf.", num1, num2, result);
            break;
        case 5:
            num1 = getInput("Please enter the base: ");
            num2 = getInput("Please enter the exponent: ");
            result = power(num1, num2);
            printf("%.2lf to the power of %.2lf is %.2lf.", num1, num2, result);
            break;
        case 6:
            num1 = getInput("Please enter the number: ");
            result = sqrt_func(num1);
            printf("The square root of %.2lf is %.2lf.", num1, result);
            break;
        case 7:
            num1 = getInput("Please enter the number: ");
            result = log_func(num1);
            printf("The natural logarithm of %.2lf is %.2lf.", num1, result);
            break;
        case 8:
            num1 = getInput("Please enter the angle in degrees: ");
            result = sin_func(num1);
            printf("The sine of %.2lf degrees is %.2lf.", num1, result);
            break;
        case 9:
            num1 = getInput("Please enter the angle in degrees: ");
            result = cos_func(num1);
            printf("The cosine of %.2lf degrees is %.2lf.", num1, result);
            break;
        case 10:
            num1 = getInput("Please enter the angle in degrees: ");
            result = tan_func(num1);
            printf("The tangent of %.2lf degrees is %.2lf.", num1, result);
            break;
        default:
            printf("Invalid input. Please try again.");
            break;
    }
    return 0;
}

double getInput(char message[]) {
    double input;
    printf("%s", message);
    scanf("%lf", &input);
    return input;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if(b == 0) {
        printf("Error: Division by zero.");
        return NAN;
    }
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}

double sqrt_func(double a) {
    return sqrt(a);
}

double log_func(double a) {
    if(a <= 0) {
        printf("Error: Logarithm of non-positive number.");
        return NAN;
    }
    return log(a);
}

double sin_func(double a) {
    a = a * M_PI / 180;
    return sin(a);
}

double cos_func(double a) {
    a = a * M_PI / 180;
    return cos(a);
}

double tan_func(double a) {
    a = a * M_PI / 180;
    return tan(a);
}