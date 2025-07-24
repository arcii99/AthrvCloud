//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);
float power(float, float);
float logarithm(float, float);

int main() {
    int choice;
    float num1, num2, result;
    
    printf("*** SCIENTIFIC CALCULATOR ***\n\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Logarithm\n");
    printf("\nEnter your choice (1-6): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\nEnter two numbers to add: ");
            scanf("%f %f", &num1, &num2);
            result = add(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case 2:
            printf("\nEnter two numbers to subtract: ");
            scanf("%f %f", &num1, &num2);
            result = subtract(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case 3:
            printf("\nEnter two numbers to multiply: ");
            scanf("%f %f", &num1, &num2);
            result = multiply(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case 4:
            printf("\nEnter two numbers to divide: ");
            scanf("%f %f", &num1, &num2);
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
                exit(0);
            }
            result = divide(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case 5:
            printf("\nEnter a base and an exponent: ");
            scanf("%f %f", &num1, &num2);
            result = power(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case 6:
            printf("\nEnter a base and a logarithm base: ");
            scanf("%f %f", &num1, &num2);
            result = logarithm(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        default:
            printf("Error: Invalid choice.\n");
            break;
    }
    
    return 0;
}

// function definitions
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

float power(float base, float exponent) {
    return pow(base, exponent);
}

float logarithm(float base, float log_base) {
    return log(base) / log(log_base);
}