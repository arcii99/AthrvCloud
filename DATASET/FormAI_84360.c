//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: standalone
#include <stdio.h>
#include <math.h>

// function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double squareRoot(double);
double logarithm(double);

int main() {
    int choice;
    double num1, num2, result;
    
    printf("\n\t\tWelcome to My Scientific Calculator\n\n");
    
    do {
        printf("\n1. Addition");
        printf("\n2. Subtraction");
        printf("\n3. Multiplication");
        printf("\n4. Division");
        printf("\n5. Power");
        printf("\n6. Square Root");
        printf("\n7. Logarithm");
        printf("\n0. Exit");
        
        printf("\nEnter your choice (0-7): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 0:
                printf("\nThank you for using my calculator!\n");
                break;
            case 1:
                printf("\nEnter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("\n%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                printf("\nEnter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("\n%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                printf("\nEnter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("\n%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                printf("\nEnter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                printf("\n%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 5:
                printf("\nEnter the base number: ");
                scanf("%lf", &num1);
                printf("Enter the exponent number: ");
                scanf("%lf", &num2);
                result = power(num1, num2);
                printf("\n%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 6:
                printf("\nEnter a number to find the square root: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                printf("\nSquare root of %.2lf = %.2lf\n", num1, result);
                break;
            case 7:
                printf("\nEnter a number to find the logarithm: ");
                scanf("%lf", &num1);
                result = logarithm(num1);
                printf("\nLogarithm of %.2lf = %.2lf\n", num1, result);
                break;
            default:
                printf("\nInvalid choice, please select from 0-7.\n");
        }
        
    } while(choice != 0);
    
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
    if (b != 0) {
        return a / b;
    } else {
        printf("\nCannot divide by zero!\n");
        return NAN;
    }
}

double power(double base, double exp) {
    return pow(base, exp);
}

double squareRoot(double num) {
    if (num >= 0) {
        return sqrt(num);
    } else {
        printf("\nCannot find square root of a negative number!\n");
        return NAN;
    }
}

double logarithm(double num) {
    if (num > 0) {
        return log(num);
    } else {
        printf("\nCannot find logarithm of a non-positive number!\n");
        return NAN;
    }
}