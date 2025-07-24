//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <math.h>

double add(double x, double y) { return x + y;}
double subtract(double x, double y) { return x - y;}
double multiply(double x, double y) { return x * y;}
double divide(double x, double y) { return x / y;}
double power(double x, double y) { return pow(x, y);}

void main()
{

    double num1, num2, result;
    char operator;
    printf("Please enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operator);
    printf("Please input the 1st number: ");
    scanf("%lf", &num1);
    printf("Please input the 2nd number: ");
    scanf("%lf", &num2);

    switch (operator) {
        case '+':
            result = add(num1, num2);
            break;

        case '-':
            result = subtract(num1, num2);
            break;

        case '*':
            result = multiply(num1, num2);
            break;

        case '/':
            result = divide(num1, num2);
           
            if (num2 == 0) {
                printf("Error: Cannot divide by zero\n");
                return 0;
                }
            break;

        case '^':
            result = power(num1, num2);
            break;
        default:
            printf("Invalid operator\n");

    } 

    printf("%.2lf %c %.2lf = %.2lf", num1, operator, num2, result);
    
}