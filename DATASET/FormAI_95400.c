//FormAI DATASET v1.0 Category: Math exercise ; Style: shocked
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Main program function */
int main()
{
    char operation;
    float num1, num2, result;
    int close = 1;

    printf("** Mathematical operations **\n\n");

    while(close) {
        printf("Enter an operator (+, -, *, /, ^, !): ");
        scanf("%c", &operation);

        if (operation == '!' || operation == '^') {
            printf("Enter a number: ");
            scanf("%f", &num1);
        } else {
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
        }

        switch(operation) {
            case '+':
                result = num1 + num2;
                printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case '*':
                result = num1 * num2;
                printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case '/':
                if(num2 == 0) {
                    printf("Division by zero is not allowed\n");
                } else {
                    result = num1 / num2;
                    printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;
            case '^':
                result = pow(num1, 3);
                printf("%.2f ^ 3 = %.2f\n", num1, result);
                break;
            case '!':
                result = 1;
                for (int i = num1; i > 1; i--) {
                    result *= i;
                }
                printf("%.2f! = %.2f\n", num1, result);
                break;
            default:
                printf("Invalid operator\n");
                break;
        }

        printf("Do you want to perform another operation? (y/n) ");
        getchar(); // To clear the '\n' from the input buffer
        if(tolower(getchar()) == 'n') {
            close = 0;
        } else {
            printf("\n");
        }
    }

    return 0;
}