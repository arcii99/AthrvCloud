//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include<stdio.h>
#include<math.h>          //For using complex mathematical calculations
#define PI 3.141592653589793 

int main()
{
    char operator;
    double num1, num2, result;

    printf("Enter an operator (+, -, *, /, ^, c, s, t, f): ");
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

        case '^':
            printf("Enter a number to get its power: ");
            scanf("%lf", &num1);
            printf("Enter the power: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
            break;

        case 'c':
            printf("Enter a number to get its cosine value: ");
            scanf("%lf", &num1);
            result = cos(num1*PI/180);
            printf("cos(%.2lf) = %.2lf", num1, result);
            break;

        case 's':
            printf("Enter a number to get its sine value: ");
            scanf("%lf", &num1);
            result = sin(num1*PI/180);
            printf("sin(%.2lf) = %.2lf", num1, result);
            break;

        case 't':
            printf("Enter a number to get its tangent value: ");
            scanf("%lf", &num1);
            result = tan(num1*PI/180);
            printf("tan(%.2lf) = %.2lf", num1, result);
            break;

        case 'f':
            printf("Enter a number to get its factorial value: ");
            scanf("%lf", &num1);
            double fac = 1;
            for(int i = 1; i <= num1; i++)
            {
                fac *= i;
            }
            printf("%.2lf! = %.2lf", num1, fac);
            break;

        default:
            printf("Error! Invalid operator");
    }

    return 0;
}