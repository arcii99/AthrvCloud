//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

int main() {
    printf("Welcome to our Scientific Calculator!\n");

    char operation;
    float num1, num2;

    printf("Please choose an operation (+,-,*,/,%,^,s,c,t): ");
    scanf("%c", &operation);

    switch (operation) {
        case '+':
            printf("Enter two numbers to add: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("Enter two numbers to subtract: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("Enter two numbers to multiply: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case '/':
            printf("Enter two numbers to divide: ");
            scanf("%f %f", &num1, &num2);
            if (num2 != 0) {
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            } else {
                printf("Error: division by zero!\n");
            }
            break;
        case '%':
            printf("Enter two numbers to find the remainder: ");
            scanf("%f %f", &num1, &num2);
            if (num2 != 0) {
                printf("%.2f %% %.2f = %.2f\n", num1, num2, fmod(num1, num2));
            } else {
                printf("Error: division by zero!\n");
            }
            break;
        case '^':
            printf("Enter a base and an exponent: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f ^ %.2f = %.2f\n", num1, num2, pow(num1, num2));
            break;
        case 's':
            printf("Enter an angle in degrees: ");
            scanf("%f", &num1);
            printf("sin(%.2f) = %.2f\n", num1, sin(num1 * M_PI / 180));
            break;
        case 'c':
            printf("Enter an angle in degrees: ");
            scanf("%f", &num1);
            printf("cos(%.2f) = %.2f\n", num1, cos(num1 * M_PI / 180));
            break;
        case 't':
            printf("Enter an angle in degrees: ");
            scanf("%f", &num1);
            printf("tan(%.2f) = %.2f\n", num1, tan(num1 * M_PI / 180));
            break;
        default:
            printf("Invalid operation entered!\n");
    }

    return 0;
}