//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include <stdio.h>
#include <math.h>

int main()
{
    char operator;
    double num1, num2;

    printf("Welcome to my Scientific Calculator\n");

    // Take input from user for operator (+, -, *, /, pow)
    printf("Enter an operator (+, -, *, /, pow): ");
    scanf("%c", &operator);

    //Take input from user for numbers
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    //Perform the operation based on the input operator
    switch(operator)
    {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1+num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1-num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1*num2);
            break;
        case '/':
            if(num2 == 0)
                printf("Error: Cannot divide by zero!\n");
            else
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1/num2);
            break;
        case 'p':   //For power operation, taking input 'p' instead of 'pow'
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, pow(num1,num2));
            break;
        default:
            printf("Invalid operator\n");
            break;
    }

    printf("Thank you for using my calculator!\n");

    return 0;
}