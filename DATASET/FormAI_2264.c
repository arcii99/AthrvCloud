//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: introspective
#include <stdio.h>
#include <math.h>

int main() {
    printf("Welcome to the Introspective C Scientific Calculator\n");
    printf("Please enter 1 for Addition\n");
    printf("Please enter 2 for Subtraction\n");
    printf("Please enter 3 for Multiplication\n");
    printf("Please enter 4 for Division\n");
    printf("Please enter 5 for Exponential Calculation\n");
    printf("Please enter 6 for Square Root Calculation\n");
    
    int userInput;
    scanf("%d", &userInput);

    while (userInput < 1 || userInput > 6) {
        printf("Invalid input, please try again\n");
        scanf("%d", &userInput);
    }

    printf("Please enter the first number: ");
    double num1;
    scanf("%lf", &num1);

    printf("Please enter the second number: ");
    double num2;
    scanf("%lf", &num2);

    double result;

    switch (userInput) {
        case 1:
            result = num1 + num2;
            printf("%lf + %lf = %lf\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("%lf - %lf = %lf\n", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("%lf * %lf = %lf\n", num1, num2, result);
            break;

        case 4:
            while (num2 == 0) {
                printf("Cannot divide by 0, please enter a non-zero value: ");
                scanf("%lf", &num2);
            }
            result = num1 / num2;
            printf("%lf / %lf = %lf\n", num1, num2, result);
            break;

        case 5:
            result = pow(num1, num2);
            printf("%lf ^ %lf = %lf\n", num1, num2, result);
            break;

        case 6:
            while (num1 < 0) {
                printf("Cannot take the square root of a negative number, please enter a non-negative value: ");
                scanf("%lf", &num1);
            }
            result = sqrt(num1);
            printf("sqrt(%lf) = %lf\n", num1, result);
            break;

        default:
            printf("Invalid input, please try again\n");
            break;
    }

    return 0;
}