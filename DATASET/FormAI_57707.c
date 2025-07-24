//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to calculate addition
double addition(double a, double b) {
    return a + b;
}

// function to calculate subtraction
double subtraction(double a, double b) {
    return a - b;
}

// function to calculate multiplication
double multiplication(double a, double b) {
    return a * b;
}

// function to calculate division
double division(double a, double b) {
    if(b == 0) {
        printf("Error: division by zero!");
        exit(0);
    }
    return a / b;
}

// function to calculate power of a number
double power(double base, double exponent) {
    return pow(base, exponent);
}

// function to calculate square root of a number
double square_root(double a) {
    if(a < 0) {
        printf("Error: square root of a negative number!");
        exit(0);
    }
    return sqrt(a);
}

// main function
int main() {
    int choice;
    double num1, num2, result;
    
    // display menu
    printf("\nWelcome to My Calculator!\n\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Exit\n\n");
    
    // get user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    // switch case to perform calculations based on user's choice
    switch(choice) {
        case 1:
            printf("\nEnter the first number: ");
            scanf("%lf", &num1);
            
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            
            result = addition(num1, num2);
            printf("\n%.2f + %.2f = %.2f", num1, num2, result);
            break;
            
        case 2:
            printf("\nEnter the first number: ");
            scanf("%lf", &num1);
            
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            
            result = subtraction(num1, num2);
            printf("\n%.2f - %.2f = %.2f", num1, num2, result);
            break;
            
        case 3:
            printf("\nEnter the first number: ");
            scanf("%lf", &num1);
            
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            
            result = multiplication(num1, num2);
            printf("\n%.2f * %.2f = %.2f", num1, num2, result);
            break;
            
        case 4:
            printf("\nEnter the first number: ");
            scanf("%lf", &num1);
            
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            
            result = division(num1, num2);
            printf("\n%.2f / %.2f = %.2f", num1, num2, result);
            break;
            
        case 5:
            printf("\nEnter the base number: ");
            scanf("%lf", &num1);
            
            printf("Enter the exponent: ");
            scanf("%lf", &num2);
            
            result = power(num1, num2);
            printf("\n%.2f ^ %.2f = %.2f", num1, num2, result);
            break;
        
        case 6:
            printf("\nEnter the number: ");
            scanf("%lf", &num1);
            
            result = square_root(num1);
            printf("\nSquare root of %.2f = %.2f", num1, result);
            break;
            
        case 7:
            printf("\nThank you for using My Calculator!");
            exit(0);
            break;
            
        default:
            printf("\nInvalid choice!");
    }
    
    return 0;
}