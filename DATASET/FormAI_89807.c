//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function declarations
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double power(double num1, double num2);
double logbase(double num1, double num2);
double sine(double num);
double cosine(double num);
double tangent(double num);
double arcsine(double num);
double arccosine(double num);
double arctangent(double num);

int main() {
    int choice;
    double result, num1, num2;

    printf("Scientific Calculator\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Logarithm\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Arcsine\n");
    printf("11. Arccosine\n");
    printf("12. Arctangent\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 4) {
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);
    } else if (choice >= 5 && choice <= 12) {
        printf("Enter number: ");
        scanf("%lf", &num1);
    }

    switch(choice) {
        case 1:
            result = add(num1, num2);
            printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
            break;
        case 4:
            result = divide(num1, num2);
            printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
            break;
        case 5:
            result = power(num1, num2);
            printf("%.2lf^%.2lf = %.2lf", num1, num2, result);
            break;
        case 6:
            result = logbase(num1, num2);
            printf("logbase%.2lf(%.2lf) = %.2lf", num1, num2, result);
            break;
        case 7:
            result = sine(num1);
            printf("sin(%.2lf) = %.2lf", num1, result);
            break;
        case 8:
            result = cosine(num1);
            printf("cos(%.2lf) = %.2lf", num1, result);
            break;
        case 9:
            result = tangent(num1);
            printf("tan(%.2lf) = %.2lf", num1, result);
            break;
        case 10:
            result = arcsine(num1);
            printf("arcsin(%.2lf) = %.2lf", num1, result);
            break;
        case 11:
            result = arccosine(num1);
            printf("arccos(%.2lf) = %.2lf", num1, result);
            break;
        case 12:
            result = arctangent(num1);
            printf("arctan(%.2lf) = %.2lf", num1, result);
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    return num1 / num2;
}

double power(double num1, double num2) {
    return pow(num1, num2);
}

double logbase(double num1, double num2) {
    return log(num2) / log(num1);
}

double sine(double num) {
    return sin(num);
}

double cosine(double num) {
    return cos(num);
}

double tangent(double num) {
    return tan(num);
}

double arcsine(double num) {
    return asin(num);
}

double arccosine(double num) {
    return acos(num);
}

double arctangent(double num) {
    return atan(num);
}