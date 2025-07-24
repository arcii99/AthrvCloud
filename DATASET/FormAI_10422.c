//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char operand;
    double num1, num2, result;
    printf("Welcome to the Curious Scientific Calculator!\n");
    printf("Please enter the first number: ");
    scanf("%lf", &num1);
    printf("Please choose an operation (+, -, *, /, ^, s, c, t): ");
    scanf(" %c", &operand);

    switch(operand) {
        case '+':
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("%lf + %lf = %lf\n", num1, num2, result);
            break;

        case '-':
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("%lf - %lf = %lf\n", num1, num2, result);
            break;

        case '*':
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("%lf * %lf = %lf\n", num1, num2, result);
            break;

        case '/':
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            if(num2 == 0.0) {
                printf("Error: division by zero\n");
                exit(0);
            }
            result = num1 / num2;
            printf("%lf / %lf = %lf\n", num1, num2, result);
            break;

        case '^':
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("%lf ^ %lf = %lf\n", num1, num2, result);
            break;

        case 's':
            result = sin(num1);
            printf("sin(%lf) = %lf\n", num1, result);
            break;

        case 'c':
            result = cos(num1);
            printf("cos(%lf) = %lf\n", num1, result);
            break;

        case 't':
            result = tan(num1);
            printf("tan(%lf) = %lf\n", num1, result);
            break;

        default:
            printf("Error: invalid operator entered\n");
            break;
    }

    printf("Thank you for using the Curious Scientific Calculator! Press Enter to exit.");
    fflush(stdin);
    getchar();

    return 0;
}