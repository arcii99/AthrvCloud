//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: inquisitive
#include <stdio.h>
#include <math.h>

// function to calculate factorial of an integer
int factorial(int num) {
    if(num == 0)
        return 1;
    else
        return num * factorial(num-1);
}

// main function
int main() {
    double num1, num2, result;
    int choice;
    
    printf("Welcome to Scientific Calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Factorial\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter two numbers to add:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
            
        case 2:
            printf("Enter two numbers to subtract:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
            
        case 3:
            printf("Enter two numbers to multiply:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
            
        case 4:
            printf("Enter two numbers to divide:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 / num2;
            printf("Result: %.2lf\n", result);
            break;
            
        case 5:
            printf("Enter a base and exponent:\n");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
            
        case 6:
            printf("Enter a number to find square root:\n");
            scanf("%lf", &num1);
            result = sqrt(num1);
            printf("Result: %.2lf\n", result);
            break;
            
        case 7:
            printf("Enter a number to find factorial:\n");
            scanf("%lf", &num1);
            result = factorial((int)num1);
            printf("Result: %.2lf\n", result);
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}