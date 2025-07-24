//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Declarations
float addition(float a, float b);
float subtraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);
float power(float a, float b);
float square_root(float a);
float absolute_value(float a);
void menu();

// Main Function
int main()
{
    char c;
    float x, y, result;
    
    do {
        menu(); // Display menu of operations
        
        printf("Enter the operation you want to perform: ");
        scanf(" %c", &c);
        
        if(c == 'Q' || c == 'q') {
            printf("Goodbye!\n");
            exit(0);
        }
        
        switch(c) {
            case '+': // Addition
                printf("Enter two numbers to add: ");
                scanf("%f %f", &x, &y);
                result = addition(x, y);
                printf("(%0.2f) + (%0.2f) = %0.2f\n", x, y, result);
                break;
            case '-': // Subtraction
                printf("Enter two numbers to subtract: ");
                scanf("%f %f", &x, &y);
                result = subtraction(x, y);
                printf("(%0.2f) - (%0.2f) = %0.2f\n", x, y, result);
                break;
            case '*': // Multiplication
                printf("Enter two numbers to multiply: ");
                scanf("%f %f", &x, &y);
                result = multiplication(x, y);
                printf("(%0.2f) * (%0.2f) = %0.2f\n", x, y, result);
                break;
            case '/': // Division
                printf("Enter two numbers to divide: ");
                scanf("%f %f", &x, &y);
                if(y == 0) {
                    printf("Cannot divide by zero! Try again.\n");
                    continue;
                }
                result = division(x, y);
                printf("(%0.2f) / (%0.2f) = %0.2f\n", x, y, result);
                break;
            case '^': // Power
                printf("Enter a base and an exponent: ");
                scanf("%f %f", &x, &y);
                result = power(x, y);
                printf("(%0.2f) ^ (%0.2f) = %0.2f\n", x, y, result);
                break;
            case 's': // Square Root
                printf("Enter a number to find its square root: ");
                scanf("%f", &x);
                if(x < 0) {
                    printf("Cannot find square root of a negative number! Try again.\n");
                    continue;
                }
                result = square_root(x);
                printf("sqrt(%0.2f) = %0.2f\n", x, result);
                break;
            case 'a': // Absolute Value
                printf("Enter a number to find its absolute value: ");
                scanf("%f", &x);
                result = absolute_value(x);
                printf("|%0.2f| = %0.2f\n", x, result);
                break;
            default: // Invalid Choice
                printf("Invalid choice! Try again.\n");
        }
    } while(c != 'Q' && c != 'q');
    
    return 0;
}

// Function Definitions
float addition(float a, float b) {
    return a + b;
}

float subtraction(float a, float b) {
    return a - b;
}

float multiplication(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    return a / b;
}

float power(float a, float b) {
    return pow(a, b);
}

float square_root(float a) {
    return sqrt(a);
}

float absolute_value(float a) {
    return fabs(a);
}

void menu() {
    printf("\n--------------------\n");
    printf("|  CALCULATOR MENU  |\n");
    printf("--------------------\n");
    printf("+ : Add\n");
    printf("- : Subtract\n");
    printf("* : Multiply\n");
    printf("/ : Divide\n");
    printf("^ : Power\n");
    printf("s : Square Root\n");
    printf("a : Absolute Value\n");
    printf("\nQ : Quit\n");
    printf("--------------------\n");
}