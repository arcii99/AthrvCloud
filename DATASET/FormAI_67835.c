//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

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
    if (b == 0) {
        printf("Error: Cannot Divide by Zero!\n");
        return -1;
    }
    return a / b;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double factorial(double n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

double sin_value(double x) {
    return sin(x * PI / 180);
}

double cos_value(double x) {
    return cos(x * PI / 180);
}

double tan_value(double x) {
    if (x == 90 || x == 270) {
        printf("Error: Value is Undefined\n");
        return -1;
    }
    return tan(x * PI / 180);
}

int main() {
    int choice;
    double a, b;
    printf("Welcome to the Ultra-Precise Scientific Calculator!\n");
    do {
        printf("\nMenu:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Factorial\n7. Sine\n8. Cosine\n9. Tangent\n0. Exit\nChoose an Option: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                printf("%.15lf\n", add(a, b));
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                printf("%.15lf\n", subtract(a, b));
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                printf("%.15lf\n", multiply(a, b));
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                printf("%.15lf\n", divide(a, b));
                break;
            case 5:
                printf("Enter base: ");
                scanf("%lf", &a);
                printf("Enter exponent: ");
                scanf("%lf", &b);
                printf("%.15lf\n", power(a, b));
                break;
            case 6:
                printf("Enter number: ");
                scanf("%lf", &a);
                printf("%.15lf\n", factorial(a));
                break;
            case 7:
                printf("Enter angle in degrees: ");
                scanf("%lf", &a);
                printf("%.15lf\n", sin_value(a));
                break;
            case 8:
                printf("Enter angle in degrees: ");
                scanf("%lf", &a);
                printf("%.15lf\n", cos_value(a));
                break;
            case 9:
                printf("Enter angle in degrees: ");
                scanf("%lf", &a);
                printf("%.15lf\n", tan_value(a));
                break;
            case 0:
                printf("Thank you for using our Ultra-Precise Scientific Calculator!\n");
                break;
            default:
                printf("Invalid Choice, Please Try Again!\n");
        }
    } while(choice != 0);
    return 0;
}