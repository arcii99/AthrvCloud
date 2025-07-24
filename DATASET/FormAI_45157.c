//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char operand;
    double num1, num2;

    printf("Welcome to the Energetic Scientific Calculator\n\n");
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the operation (+, -, *, /, ^, sqrt): ");
    scanf(" %c", &operand);

    switch(operand) {
        case '+':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            printf("%.2lf + %.2lf = %.2lf", num1, num2, num1+num2);
            break;

        case '-':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            printf("%.2lf - %.2lf = %.2lf", num1, num2, num1-num2);
            break;

        case '*':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            printf("%.2lf * %.2lf = %.2lf", num1, num2, num1*num2);
            break;

        case '/':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            printf("%.2lf / %.2lf = %.2lf", num1, num2, num1/num2);
            break;

        case '^':
            printf("Enter the exponent: ");
            scanf("%lf", &num2);
            printf("%.2lf ^ %.2lf = %.2lf", num1, num2, pow(num1,num2));
            break;

        case 's': // used for sqrt since 'sqrt' starts with an 's'
            printf("The square root of %.2lf = %.2lf", num1, sqrt(num1));
            break;

        default:
            printf("Invalid operation entered.");
    }
    return 0;
}