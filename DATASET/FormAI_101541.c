//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double num1, num2, result;

    printf("Welcome to the Intelligent Scientific Calculator!\n");
    
    do {
        
        printf("\nPlease select an operation: \n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Square root (√)\n");
        printf("6. Exponentiation (xⁿ)\n");
        printf("7. Factorial (n!)\n");
        printf("8. Trigonometric functions (sin, cos, tan)\n");
        printf("9. Logarithm (ln)\n");
        printf("0. Quit Calculator\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Addition Operation Selected\n");
                printf("Please enter the first number: ");
                scanf("%lf", &num1);
                printf("Please enter the second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("Result: %lf\n", result);
                break;
            case 2:
                printf("Subtraction Operation Selected\n");
                printf("Please enter the first number: ");
                scanf("%lf", &num1);
                printf("Please enter the second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("Result: %lf\n", result);
                break;
            case 3:
                printf("Multiplication Operation Selected\n");
                printf("Please enter the first number: ");
                scanf("%lf", &num1);
                printf("Please enter the second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("Result: %lf\n", result);
                break;
            case 4:
                printf("Division Operation Selected\n");
                printf("Please enter the dividend: ");
                scanf("%lf", &num1);
                printf("Please enter the divisor: ");
                scanf("%lf", &num2);
                while (num2 == 0) {
                    printf("Math Error: Can't divide by zero\n");
                    printf("Please enter a non-zero number: ");
                    scanf("%lf", &num2);
                }
                result = num1 / num2;
                printf("Result: %lf\n", result);
                break;
            case 5:
                printf("Square Root Operation Selected\n");
                printf("Please enter a non-negative number: ");
                scanf("%lf", &num1);
                while (num1 < 0) {
                    printf("Math Error: Can't find square root of negative number\n");
                    printf("Please enter a non-negative number: ");
                    scanf("%lf", &num1);
                }
                result = sqrt(num1);
                printf("Result: %lf\n", result);
                break;
            case 6:
                printf("Exponentiation Operation Selected\n");
                printf("Please enter the base: ");
                scanf("%lf", &num1);
                printf("Please enter the exponent: ");
                scanf("%lf", &num2);
                result = pow(num1,num2);
                printf("Result: %lf\n", result);
                break;
            case 7:
                printf("Factorial Operation Selected\n");
                printf("Please enter a non-negative integer: ");
                scanf("%lf", &num1);
                while (num1 < 0 || fmod(num1,1) != 0) {
                    printf("Math Error: Can't find factorial of a non-negative non-integer number\n");
                    printf("Please enter a non-negative integer: ");
                    scanf("%lf", &num1);
                }
                result = 1;
                for(int i=1; i<=num1; i++) {
                    result *= i;
                }
                printf("Result: %lf\n", result);
                break;
            case 8:
                printf("Trigonometric Functions Operation Selected\n");
                printf("Please enter the angle in radians: ");
                scanf("%lf", &num1);
                printf("sin(%lf) = %lf \n", num1, sin(num1));
                printf("cos(%lf) = %lf \n", num1, cos(num1));
                printf("tan(%lf) = %lf \n", num1, tan(num1));
                break;
            case 9:
                printf("Natural Logarithm Operation Selected\n");
                printf("Please enter a positive number: ");
                scanf("%lf", &num1);
                while (num1 <= 0) {
                    printf("Math Error: Can't find logarithm of non-positive number\n");
                    printf("Please enter a positive number: ");
                    scanf("%lf", &num1);
                }
                result = log(num1);
                printf("Result: %lf\n", result);
                break;
            case 0:
                printf("Thanks for using the Intelligent Scientific Calculator!\n");
                break;
            default:
                printf("Invalid Choice... Please choose from the menu!\n");
        }
        
    } while(choice != 0);

    return 0;
}