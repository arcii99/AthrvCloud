//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Touring
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main()
{
    double x, y;
    char op;

    printf("Welcome to my scientific calculator!\n\n");
    printf("Enter operator (+, -, *, /, ^, s, c, t): ");
    scanf("%c", &op);

    switch(op)
    {
        case 's':
        case 'c':
        case 't':
            printf("Enter angle in degrees: ");
            scanf("%lf", &x);
            x = x * 0.0174533; // convert degrees to radians
            break;
        default:
            printf("Enter first number: ");
            scanf("%lf", &x);
            printf("Enter second number: ");
            scanf("%lf", &y);
            break;
    }

    switch(op)
    {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", x, y, x + y);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", x, y, x - y);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", x, y, x * y);
            break;
        case '/':
            if(y==0)
                printf("Error: Division by zero\n");
            else
                printf("%.2lf / %.2lf = %.2lf\n", x, y, x / y);
            break;
        case '^':
            printf("%.2lf ^ %.2lf = %.2lf\n", x, y, pow(x,y));
            break;
        case 's':
            printf("sin(%.2lf) = %.2lf\n", x, sin(x));
            break;
        case 'c':
            printf("cos(%.2lf) = %.2lf\n", x, cos(x));
            break;
        case 't':
            printf("tan(%.2lf) = %.2lf\n", x, tan(x));
            break;
        default:
            printf("Error: Invalid operator\n");
            break;
    }

    return 0;
}