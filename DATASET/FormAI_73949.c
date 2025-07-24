//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <math.h>

int main()
{
    double number;
    char operator;

    printf("Welcome to our Scientific Calculator!\n");
    printf("Enter a number: ");
    scanf("%lf", &number);

    printf("Enter an operator (+, -, *, /, ^, sin, cos, tan, sqrt): ");
    scanf(" %c", &operator);

    switch(operator)
    {
        case '+':
            printf("Enter a number to add: ");
            double add;
            scanf("%lf", &add);
            printf("%.2lf + %.2lf = %.2lf\n", number, add, number+add);
            break;
        case '-':
            printf("Enter a number to subtract: ");
            double subtract;
            scanf("%lf", &subtract);
            printf("%.2lf - %.2lf = %.2lf\n", number, subtract, number-subtract);
            break;
        case '*':
            printf("Enter a number to multiply: ");
            double multiply;
            scanf("%lf", &multiply);
            printf("%.2lf * %.2lf = %.2lf\n", number, multiply, number*multiply);
            break;
        case '/':
            printf("Enter a number to divide: ");
            double divide;
            scanf("%lf", &divide);
            if(divide==0)
            {
                printf("Error: Divide by 0\n");
            }
            else
            {
                printf("%.2lf / %.2lf = %.2lf\n", number, divide, number/divide);
            }
            break;
        case '^':
            printf("Enter the power to raise to (integer): ");
            int power;
            scanf("%d", &power);
            printf("%.2lf ^ %d = %.2lf\n", number, power, pow(number, power));
            break;
        case 's':
        case 'S':
            printf("sin(%.2lf) = %.2lf\n", number, sin(number));
            break;
        case 'c':
        case 'C':
            printf("cos(%.2lf) = %.2lf\n", number, cos(number));
            break;
        case 't':
        case 'T':
            printf("tan(%.2lf) = %.2lf\n", number, tan(number));
            break;
        case 'q':
        case 'Q':
            if(number<0)
            {
                printf("Error: Square root of negative number\n");
            }
            else
            {
                printf("sqrt(%.2lf) = %.2lf\n", number, sqrt(number));
            }
            break;
        default:
            printf("Error: Invalid operator\n");
    }

    printf("Thank you for using our Scientific Calculator!");

    return 0;
}