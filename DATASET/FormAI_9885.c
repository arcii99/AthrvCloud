//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
#include<stdio.h>
#include<math.h>

int main()
{
    char operator;
    double num1, num2, result;

    printf("Enter an operator (+, -, *, /, ^, sin, cos, tan, log): ");
    scanf("%c", &operator);

    switch(operator)
    {
        case '+':
            printf("Enter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
            break;

        case '-':
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
            break;

        case '*':
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
            break;

        case '/':
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            if(num2 == 0){
                printf("Error: Cannot Divide By Zero");
                break;
            }
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
            break;

        case '^':
            printf("Enter two numbers for base and power: ");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
            break;

        case 's':
            printf("Enter number for sin calculation: ");
            scanf("%lf", &num1);
            result = sin(num1);
            printf("sin(%.2lf) = %.2lf", num1, result);
            break;

        case 'c':
            printf("Enter number for cos calculation: ");
            scanf("%lf", &num1);
            result = cos(num1);
            printf("cos(%.2lf) = %.2lf", num1, result);
            break;

        case 't':
            printf("Enter number for tan calculation: ");
            scanf("%lf", &num1);
            if(cos(num1) == 0){
                printf("Error: Undefined result for tan(%.2lf)", num1);
                break;
            }
            result = tan(num1);
            printf("tan(%.2lf) = %.2lf", num1, result);
            break;

        case 'l':
            printf("Enter number for log calculation: ");
            scanf("%lf", &num1);
            if(num1 <= 0){
                printf("Error: Invalid input for log function");
                break;
            }
            result = log10(num1);
            printf("log(%.2lf) = %.2lf", num1, result);
            break;

        default:
            printf("Error: Invalid Operator");
    }

    return 0;
}