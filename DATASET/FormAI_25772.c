//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    This is a unique implementation of a scientific calculator in C.
    It uses a switch case to handle different operations that are 
    supported by the calculator. It has a simple interface that allows
    the user to enter an operation and then the operands. After the
    calculation is done, it displays the result.

    Made by [YOUR NAME]
    Last modified: [DATE]
*/

int main()
{
    int choice;
    double a, b, result;
    printf("Welcome to the C Scientific Calculator!\n");

    while(1){
        printf("Enter your choice:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square Root\n");
        printf("6. Power of x\n");
        printf("7. Logarithm (base 10)\n");
        printf("8. Logarithm (base e)\n");
        printf("9. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%lf %lf", &a, &b);
                result = a + b;
                printf("Result: %f\n", result);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%lf %lf", &a, &b);
                result = a - b;
                printf("Result: %f\n", result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%lf %lf", &a, &b);
                result = a * b;
                printf("Result: %f\n", result);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%lf %lf", &a, &b);
                if(b == 0){
                    printf("Error: Division by zero is not defined!\n");
                    break;
                }
                result = a / b;
                printf("Result: %f\n", result);
                break;
            case 5:
                printf("Enter a number to calculate square root: ");
                scanf("%lf", &a);
                if(a < 0){
                    printf("Error: Cannot calculate square root of negative number!\n");
                    break;
                }
                result = sqrt(a);
                printf("Result: %f\n", result);
                break;
            case 6:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                result = pow(a, b);
                printf("Result: %f\n", result);
                break;
            case 7:
                printf("Enter a number to calculate log (base 10): ");
                scanf("%lf", &a);
                if(a <= 0){
                    printf("Error: Cannot calculate log of non-positive number!\n");
                    break;
                }
                result = log10(a);
                printf("Result: %f\n", result);
                break;
            case 8:
                printf("Enter a number to calculate natural logarithm: ");
                scanf("%lf", &a);
                if(a <= 0){
                    printf("Error: Cannot calculate log of non-positive number!\n");
                    break;
                }
                result = log(a);
                printf("Result: %f\n", result);
                break;
            case 9:
                printf("Bye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
                break;
        }
    }

    return 0;
}