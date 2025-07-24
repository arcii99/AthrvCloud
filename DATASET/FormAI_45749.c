//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Welcome to the world's most amazing calculator!
// You can do basic arithmetic operations or even calculate the circumference of a pizza!
// Let's get started!

int main() {
    char operator;
    double first_number, second_number, result;

    printf("Welcome to the world's most amazing calculator!\n");
    printf("Enter '+' for addition, '-' for subtraction, '*' for multiplication, '/' for division, '%' for modulus, '^' for power, 'r' for square root, and 'p' for the circumference of a pizza!:\n");
    
    scanf("%c", &operator);

    switch(operator) {
        case '+':
            printf("Enter the first number: ");
            scanf("%lf", &first_number);

            printf("Enter the second number: ");
            scanf("%lf", &second_number);

            result = first_number + second_number;
            printf("The sum is: %lf\n", result);
            break;

        case '-':
            printf("Enter the first number: ");
            scanf("%lf", &first_number);

            printf("Enter the second number: ");
            scanf("%lf", &second_number);

            result = first_number - second_number;
            printf("The difference is: %lf\n", result);
            break;

        case '*':
            printf("Enter the first number: ");
            scanf("%lf", &first_number);

            printf("Enter the second number: ");
            scanf("%lf", &second_number);

            result = first_number * second_number;
            printf("The product is: %lf\n", result);
            break;

        case '/':
            printf("Enter the first number: ");
            scanf("%lf", &first_number);

            printf("Enter the second number: ");
            scanf("%lf", &second_number);

            if(second_number == 0) {
                printf("Error! Cannot divide by zero.\n");
                break;
            } else {
                result = first_number / second_number;
                printf("The quotient is: %lf\n", result);
            }
            break;

        case '%':
            printf("Enter the first number: ");
            scanf("%lf", &first_number);

            printf("Enter the second number: ");
            scanf("%lf", &second_number);

            result = fmod(first_number, second_number);
            printf("The modulus is: %lf\n", result);
            break;

        case '^':
            printf("Enter the base number: ");
            scanf("%lf", &first_number);

            printf("Enter the exponent: ");
            scanf("%lf", &second_number);

            result = pow(first_number, second_number);
            printf("The result is: %lf\n", result);
            break;

        case 'r':
            printf("Enter a number to get its square root: ");
            scanf("%lf", &first_number);

            result = sqrt(first_number);
            printf("The square root is: %lf\n", result);
            break;
        
        case 'p':
            printf("Enter the diameter of the pizza in inches: ");
            scanf("%lf", &first_number);

            result = first_number * M_PI;
            printf("The circumference of the pizza is: %lf inches\n", result);
            break;

        default:
            printf("Invalid operator entered!\n");
            break;
    }

    return 0;
}