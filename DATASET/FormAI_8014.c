//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: standalone
#include <stdio.h>
#include <math.h>

int main()
{
    char operation;
    float num1, num2, result;

    printf("Welcome to the Scientific Calculator\n");
    printf("Please select the operation you would like to perform:\n");
    printf("+ for Addition\n- for Subtraction\n* for Multiplication\n/ for Division\n^ for Exponentiation\ns for Square Root\n");

    scanf("%c", &operation);

    switch(operation)
    {
        case '+':
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("The result is %.2f", result);
            break;

        case '-':
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("The result is %.2f", result);
            break;

        case '*':
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("The result is %.2f", result);
            break;
            
        case '/':
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 / num2;
            printf("The result is %.2f", result);
            break;
            
        case '^':
            printf("Enter the base number: ");
            scanf("%f", &num1);
            printf("Enter the exponent: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("The result is %.2f", result);
            break;
            
        case 's':
            printf("Enter the number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("The result is %.2f", result);
            break;
            
        default:
            printf("Invalid operation selected!");
            break;
    }

    return 0;
}