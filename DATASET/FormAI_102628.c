//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ephemeral
// Advanced Scientific Calculator Program in C
 
#include <stdio.h>
#include <math.h>
#include <ctype.h>
 
int main()
{
    char operator;
    double a, b;
 
    printf("Please Enter an Operator (+, -, *, /, ^, s, c): ");
    scanf("%c", &operator);
 
    switch(operator)
    {
        case '+':
            printf("Please Enter the First Operand: ");
            scanf("%lf", &a);
            printf("Please Enter the Second Operand: ");
            scanf("%lf", &b);
            printf("%.2lf + %.2lf = %.2lf\n", a, b, a + b);
            break;
        case '-':
            printf("Please Enter the First Operand: ");
            scanf("%lf", &a);
            printf("Please Enter the Second Operand: ");
            scanf("%lf", &b);
            printf("%.2lf - %.2lf = %.2lf\n", a, b, a - b);
            break;
        case '*':
            printf("Please Enter the First Operand: ");
            scanf("%lf", &a);
            printf("Please Enter the Second Operand: ");
            scanf("%lf", &b);
            printf("%.2lf * %.2lf = %.2lf\n", a, b, a * b);
            break;
        case '/':
            printf("Please Enter the First Operand: ");
            scanf("%lf", &a);
            printf("Please Enter the Second Operand: ");
            scanf("%lf", &b);
            if(b != 0)
                printf("%.2lf / %.2lf = %.2lf\n", a, b, a / b);
            else
                printf("Cannot Divide by Zero\n");
            break;
        case '^':
            printf("Please Enter the Base: ");
            scanf("%lf", &a);
            printf("Please Enter the Power: ");
            scanf("%lf", &b);
            printf("%.2lf ^ %.2lf = %.2lf\n", a, b, pow(a, b));
            break;
        case 's':
            printf("Please Enter the Angle in Degrees: ");
            scanf("%lf", &a);
            printf("sin(%.2lf) = %.2lf\n", a, sin(a * M_PI / 180));
            break;
        case 'c':
            printf("Please Enter the Angle in Degrees: ");
            scanf("%lf", &a);
            printf("cos(%.2lf) = %.2lf\n", a, cos(a * M_PI / 180));
            break;
        default:
            printf("Invalid Operator\n");
    }
 
    return 0;
}