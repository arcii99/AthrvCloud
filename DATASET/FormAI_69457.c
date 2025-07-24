//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char operator;
    double num1, num2, result;

    printf("Welcome to the Super Scientific Calculator\n");

    printf("Enter + for Addition\n");
    printf("Enter - for Subtraction\n");
    printf("Enter * for Multiplication\n");
    printf("Enter / for Division\n");
    printf("Enter p for Power\n");
    printf("Enter s for Square root\n");
    printf("Enter r for Round\n");
    printf("Enter f for Factorial\n");    

    printf("Enter the operator of your choice: ");
    scanf("%c", &operator);

    switch(operator)
    {
        case '+':
            printf("Enter two numbers to add: ");
            scanf("%lf %lf",&num1, &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf",num1, num2, result);
            break;

        case '-':
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf",&num1, &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf",num1, num2, result);
            break;

        case '*':
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf",&num1, &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf",num1, num2, result);
            break;

        case '/':
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf",&num1, &num2);
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf",num1, num2, result);
            break;

        case 'p':
            printf("Enter the value and power you want to calculate: ");
            scanf("%lf %lf",&num1, &num2);
            result = pow(num1, num2);
            printf("%.2lf^%.2lf = %.2lf",num1, num2, result);
            break;

        case 's':
            printf("Enter the value you want to find the square root of: ");
            scanf("%lf",&num1);
            result = sqrt(num1);
            printf("The square root of %.2lf is %.2lf",num1, result);
            break;

        case 'r':
            printf("Enter the value you want to round: ");
            scanf("%lf",&num1);
            result = round(num1);
            printf("The rounded value of %.2lf is %.0lf",num1, result);
            break;

        case 'f':
            printf("Enter the value you want to find the factorial of: ");
            scanf("%lf",&num1);
            result = 1;
            for(int i = 1; i <= num1; i++)
            {
                result *= i;
            }
            printf("%.2lf! = %.0lf",num1, result);
            break;

        default:
            printf("Invalid operator!");
            break;
    }

    return 0;
}