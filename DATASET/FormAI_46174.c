//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: interoperable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double square(double a);
double sqroot(double a);
double sin_degrees(double a);
double cos_degrees(double a);
double tan_degrees(double a);
double asin_degrees(double a);
double acos_degrees(double a);
double atan_degrees(double a);

int main() {
    char op;
    double a, b, result;

    printf("Welcome to the Scientific Calculator!\n");
    printf("Please enter an operation (+, -, *, /, ^, s, r, S, C, T, A, B, Y): ");
    scanf("%c", &op);

    switch (op) {
        case '+':
            printf("Please enter the first number: ");
            scanf("%lf", &a);
            printf("Please enter the second number: ");
            scanf("%lf", &b);
            result = add(a, b);
            printf("%lf + %lf = %lf\n", a, b, result);
            break;
        case '-':
            printf("Please enter the first number: ");
            scanf("%lf", &a);
            printf("Please enter the second number: ");
            scanf("%lf", &b);
            result = subtract(a, b);
            printf("%lf - %lf = %lf\n", a, b, result);
            break;
        case '*':
            printf("Please enter the first number: ");
            scanf("%lf", &a);
            printf("Please enter the second number: ");
            scanf("%lf", &b);
            result = multiply(a, b);
            printf("%lf * %lf = %lf\n", a, b, result);
            break;
        case '/':
            printf("Please enter the first number: ");
            scanf("%lf", &a);
            printf("Please enter the second number: ");
            scanf("%lf", &b);
            if (b == 0) {
                printf("Error: Division by zero\n");
                return 0;
            }
            result = divide(a, b);
            printf("%lf / %lf = %lf\n", a, b, result);
            break;
        case '^':
            printf("Please enter the base: ");
            scanf("%lf", &a);
            printf("Please enter the exponent: ");
            scanf("%lf", &b);
            result = power(a, b);
            printf("%lf ^ %lf = %lf\n", a, b, result);
            break;
        case 's':
            printf("Please enter the number to square: ");
            scanf("%lf", &a);
            result = square(a);
            printf("%lf ^ 2 = %lf\n", a, result);
            break;
        case 'r':
            printf("Please enter the number to find the square root of: ");
            scanf("%lf", &a);
            result = sqroot(a);
            printf("sqrt(%lf) = %lf\n", a, result);
            break;
        case 'S':
            printf("Please enter the angle in degrees: ");
            scanf("%lf", &a);
            result = sin_degrees(a);
            printf("sin(%lf) = %lf\n", a, result);
            break;
        case 'C':
            printf("Please enter the angle in degrees: ");
            scanf("%lf", &a);
            result = cos_degrees(a);
            printf("cos(%lf) = %lf\n", a, result);
            break;
        case 'T':
            printf("Please enter the angle in degrees: ");
            scanf("%lf", &a);
            result = tan_degrees(a);
            printf("tan(%lf) = %lf\n", a, result);
            break;
        case 'A':
            printf("Please enter the value: ");
            scanf("%lf", &a);
            result = asin_degrees(a);
            printf("asin(%lf) = %lf\n", a, result);
            break;
        case 'B':
            printf("Please enter the value: ");
            scanf("%lf", &a);
            result = acos_degrees(a);
            printf("acos(%lf) = %lf\n", a, result);
            break;
        case 'Y':
            printf("Please enter the value: ");
            scanf("%lf", &a);
            result = atan_degrees(a);
            printf("atan(%lf) = %lf\n", a, result);
            break;
        default:
            printf("Invalid operation\n");
            break;
    }

    return 0;
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
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}

double square(double a) {
    return pow(a, 2);
}

double sqroot(double a) {
    return sqrt(a);
}

double sin_degrees(double a) {
    return sin(a * PI / 180);
}

double cos_degrees(double a) {
    return cos(a * PI / 180);
}

double tan_degrees(double a) {
    return tan(a * PI / 180);
}

double asin_degrees(double a) {
    return asin(a) * 180 / PI;
}

double acos_degrees(double a) {
    return acos(a) * 180 / PI;
}

double atan_degrees(double a) {
    return atan(a) * 180 / PI;
}