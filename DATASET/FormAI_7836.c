//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

// function declarations
double addition(double a, double b);
double subtraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);
double power(double a, double b);
double square_root(double a);
double modulus(double a, double b);

// main function
int main() {
    int choice;
    double num1, num2, result;
    
    printf("Welcome to Calculator!\n\n");
    printf("Choose an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Power (^)\n");
    printf("6. Square Root (√)\n");
    printf("7. Modulus (%)\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter two numbers for addition: ");
            scanf("%lf %lf", &num1, &num2);
            result = addition(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        
        case 2:
            printf("Enter two numbers for subtraction: ");
            scanf("%lf %lf", &num1, &num2);
            result = subtraction(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        
        case 3:
            printf("Enter two numbers for multiplication: ");
            scanf("%lf %lf", &num1, &num2);
            result = multiplication(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        
        case 4:
            printf("Enter two numbers for division: ");
            scanf("%lf %lf", &num1, &num2);
            result = division(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        
        case 5:
            printf("Enter two numbers for power: ");
            scanf("%lf %lf", &num1, &num2);
            result = power(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        
        case 6:
            printf("Enter number for square root: ");
            scanf("%lf", &num1);
            result = square_root(num1);
            printf("Result: %.2lf\n", result);
            break;
        
        case 7:
            printf("Enter two numbers for modulus: ");
            scanf("%lf %lf", &num1, &num2);
            result = modulus(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        
        default:
            printf("Invalid Choice!");
            break;
    }
    
    return 0;
}

// function definitions
double addition(double a, double b) {
    return a + b;
}

double subtraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}

double square_root(double a) {
    return sqrt(a);
}

double modulus(double a, double b) {
    return fmod(a, b);
}