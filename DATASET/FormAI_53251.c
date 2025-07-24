//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    char operator;
    double num1, num2;
    int flag = 0;
    printf("Welcome to the Secure C Scientific Calculator!\n");
    printf("==============\n");
    printf("Please enter an operator (+, -, *, /, ^, s) or type q to quit: ");
    scanf("%c", &operator);

    while(operator != 'q')
    {
        flag = 0;
        switch(operator)
        {
            case '+':
                printf("Enter two operands separated by space: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("Enter two operands separated by space: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("Enter two operands separated by space: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
                break;
            case '/':
                printf("Enter two operands separated by space: ");
                scanf("%lf %lf", &num1, &num2);
                if(num2 == 0)
                {
                    printf("Error: Division by zero is undefined.\n");
                    break;
                }
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
                break;
            case '^':
                printf("Enter two operands separated by space: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, pow(num1, num2));
                break;
            case 's':
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("sqrt(%.2lf) = %.2lf\n", num1, sqrt(num1));
                break;
            default:
                printf("Invalid operator! Please try again.\n");
                flag = 1;
        }
        if(!flag)
        {
            printf("Please enter an operator (+, -, *, /, ^, s) or type q to quit: ");
            getchar();
            scanf("%c", &operator);
        }
        else
        {
            printf("Please enter an operator (+, -, *, /, ^, s) or type q to quit: ");
            getchar();
            scanf("%c", &operator);
            flag = 0;
        }
    }
    printf("Thank you for using the Secure C Scientific Calculator!\n");
    return 0;
}