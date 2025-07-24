//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
#include <stdio.h>
#include <math.h>

int main() {
    printf("Welcome to the scientific calculator!\n");
    printf("Please choose an operator:\n");
    printf("1 - Addition\n");
    printf("2 - Subtraction\n");
    printf("3 - Multiplication\n");
    printf("4 - Division\n");
    printf("5 - Square root\n");
    printf("6 - Power of\n");
    
    int op;
    scanf("%d", &op);
    
    if (op < 1 || op > 6) {
        printf("Invalid operator!\n");
        printf("Exiting program...\n");
        return 0;
    }
    
    switch(op) {
        case 1: {
            printf("Addition selected.\n");
            printf("Please enter two numbers to add:\n");
            double x, y, result;
            scanf("%lf %lf", &x, &y);
            result = x + y;
            printf("%.2lf + %.2lf = %.2lf\n", x, y, result);
            break;
        }
        case 2: {
            printf("Subtraction selected.\n");
            printf("Please enter two numbers to subtract:\n");
            double x, y, result;
            scanf("%lf %lf", &x, &y);
            result = x - y;
            printf("%.2lf - %.2lf = %.2lf\n", x, y, result);
            break;
        }
        case 3: {
            printf("Multiplication selected.\n");
            printf("Please enter two numbers to multiply:\n");
            double x, y, result;
            scanf("%lf %lf", &x, &y);
            result = x * y;
            printf("%.2lf x %.2lf = %.2lf\n", x, y, result);
            break;
        }
        case 4: {
            printf("Division selected.\n");
            printf("Please enter two numbers to divide:\n");
            double x, y, result;
            scanf("%lf %lf", &x, &y);
            if (y == 0) {
                printf("Cannot divide by zero!\n");
                printf("Exiting program...\n");
                return 0;
            }
            result = x / y;
            printf("%.2lf / %.2lf = %.2lf\n", x, y, result);
            break;
        }
        case 5: {
            printf("Square root selected.\n");
            printf("Please enter a number to square root:\n");
            double x, result;
            scanf("%lf", &x);
            if (x < 0) {
                printf("Cannot square root a negative number!\n");
                printf("Exiting program...\n");
                return 0;
            }
            result = sqrt(x);
            printf("sqrt(%.2lf) = %.2lf\n", x, result);
            break;
        }
        case 6: {
            printf("Power of selected.\n");
            printf("Please enter two numbers:\n");
            double x, y, result;
            scanf("%lf %lf", &x, &y);
            result = pow(x, y);
            printf("%.2lf ^ %.2lf = %.2lf\n", x, y, result);
            break;
        }
    }
    
    printf("Exiting program...\n");
    return 0;
}