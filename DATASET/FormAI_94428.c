//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Welcome to Alan Turing Scientific Calculator\n");

    // User input
    printf("Enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    // Calculation based on operator
    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero\n");
                exit(0);
            }
            result = num1 / num2;
            break;
        case '^':
            result = pow(num1, num2);
            break;
        default:
            printf("Error: Invalid operator\n");
            exit(0);
    }

    // Displaying the result
    printf("\nResult: %lf %c %lf = %lf\n", num1, operator, num2, result);

    return 0;
}