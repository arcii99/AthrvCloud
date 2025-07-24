//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <math.h>

// Function declarations
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double power(double base, double exponent);
double sqrt(double num);
double cube(double num);
double absolute(double num);
double factorial(double num);
double sin_degrees(double degrees);
double cos_degrees(double degrees);
double tan_degrees(double degrees);
double arcsin_degrees(double num);
double arccos_degrees(double num);
double arctan_degrees(double num);

int main() {
    int option;
    double num1, num2;
    printf("********** SCIENTIFIC CALCULATOR **********\n");
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Cube\n");
    printf("8. Absolute\n");
    printf("9. Factorial\n");
    printf("10. Sine\n");
    printf("11. Cosine\n");
    printf("12. Tangent\n");
    printf("13. Arcsine\n");
    printf("14. Arccosine\n");
    printf("15. Arctangent\n");
    printf("Option: ");
    scanf("%d", &option);
    switch(option) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, add(num1, num2));
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, subtract(num1, num2));
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, multiply(num1, num2));
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, divide(num1, num2));
            break;
        case 5:
            printf("Enter the base: ");
            scanf("%lf", &num1);
            printf("Enter the exponent: ");
            scanf("%lf", &num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, power(num1, num2));
            break;
        case 6:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            printf("sqrt(%.2lf) = %.2lf\n", num1, sqrt(num1));
            break;
        case 7:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            printf("cube(%.2lf) = %.2lf\n", num1, cube(num1));
            break;
        case 8:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            printf("|%.2lf| = %.2lf\n", num1, absolute(num1));
            break;
        case 9:
            printf("Enter a positive integer: ");
            scanf("%lf", &num1);
            printf("%.2lf! = %.2lf\n", num1, factorial(num1));
            break;
        case 10:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &num1);
            printf("sin(%.2lf) = %.2lf\n", num1, sin_degrees(num1));
            break;
        case 11:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &num1);
            printf("cos(%.2lf) = %.2lf\n", num1, cos_degrees(num1));
            break;
        case 12:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &num1);
            printf("tan(%.2lf) = %.2lf\n", num1, tan_degrees(num1));
            break;
        case 13:
            printf("Enter the value of sin(x): ");
            scanf("%lf", &num1);
            printf("arcsin(%.2lf) = %.2lf\n", num1, arcsin_degrees(num1));
            break;
        case 14:
            printf("Enter the value of cos(x): ");
            scanf("%lf", &num1);
            printf("arccos(%.2lf) = %.2lf\n", num1, arccos_degrees(num1));
            break;
        case 15:
            printf("Enter the value of tan(x): ");
            scanf("%lf", &num1);
            printf("arctan(%.2lf) = %.2lf\n", num1, arctan_degrees(num1));
            break;
        default:
            printf("Invalid option!\n");
    }
    return 0;
}

// Function definitions
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
    if(num2 == 0) {
        printf("Error: division by zero\n");
        return 0;
    }
    return num1 / num2;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double sqrt(double num) {
    if(num < 0) {
        printf("Error: square root of negative number\n");
        return 0;
    }
    return sqrt(num);
}

double cube(double num) {
    return pow(num, 3);
}

double absolute(double num) {
    return fabs(num);
}

double factorial(double num) {
    if(num < 0) {
        printf("Error: factorial of negative number\n");
        return 0;
    }
    double result = 1;
    for(int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

double sin_degrees(double degrees) {
    double radians = degrees * (M_PI / 180);
    return sin(radians);
}

double cos_degrees(double degrees) {
    double radians = degrees * (M_PI / 180);
    return cos(radians);
}

double tan_degrees(double degrees) {
    double radians = degrees * (M_PI / 180);
    return tan(radians);
}

double arcsin_degrees(double num) {
    if(num < -1 || num > 1) {
        printf("Error: arcsin of number outside [-1, 1]\n");
        return 0;
    }
    double radians = asin(num);
    return (radians * 180) / M_PI;
}

double arccos_degrees(double num) {
    if(num < -1 || num > 1) {
        printf("Error: arccos of number outside [-1, 1]\n");
        return 0;
    }
    double radians = acos(num);
    return (radians * 180) / M_PI;
}

double arctan_degrees(double num) {
    double radians = atan(num);
    return (radians * 180) / M_PI;
}