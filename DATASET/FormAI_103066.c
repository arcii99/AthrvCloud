//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265

int main(){

    char operator;
    double num1, num2;

    printf("Enter an operator (+, -, *, /, sin, cos, tan, log, ^, sqrt):\n");
    scanf("%c", &operator);

    switch(operator){

        case '+':
            printf("Enter two numbers to add:\n");
            scanf("%lf %lf", &num1, &num2);
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1+num2);
            break;

        case '-':
            printf("Enter two numbers to subtract:\n");
            scanf("%lf %lf", &num1, &num2);
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1-num2);
            break;

        case '*':
            printf("Enter two numbers to multiply:\n");
            scanf("%lf %lf", &num1, &num2);
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1*num2);
            break;

        case '/':
            printf("Enter two numbers to divide:\n");
            scanf("%lf %lf", &num1, &num2);
            if(num2 != 0)
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1/num2);
            else
                printf("Error: Division by zero.\n");
            break;

        case 's':
            printf("Enter an angle in degrees to find sine value:\n");
            scanf("%lf", &num1);
            printf("Sine of %.2lf degrees = %.2lf\n", num1, sin(num1*PI/180));
            break;

        case 'c':
            printf("Enter an angle in degrees to find cosine value:\n");
            scanf("%lf", &num1);
            printf("Cosine of %.2lf degrees = %.2lf\n", num1, cos(num1*PI/180));
            break;

        case 't':
            printf("Enter an angle in degrees to find tangent value:\n");
            scanf("%lf", &num1);
            printf("Tangent of %.2lf degrees = %.2lf\n", num1, tan(num1*PI/180));
            break;

        case 'l':
            printf("Enter a number to find natural log value:\n");
            scanf("%lf", &num1);
            if(num1 > 0)
                printf("Natural log of %.2lf = %.2lf\n", num1, log(num1));
            else
                printf("Error: Logarithm of a non-positive number.\n");
            break;

        case '^':
            printf("Enter base and exponent:\n");
            scanf("%lf %lf", &num1, &num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, pow(num1,num2));
            break;

        case 'q':
            printf("Enter a number to find square root:\n");
            scanf("%lf", &num1);
            if(num1 >= 0)
                printf("Square root of %.2lf = %.2lf\n", num1, sqrt(num1));
            else
                printf("Error: Square root of a negative number.\n");
            break;

        default:
            printf("Error: Invalid operator.\n");

    }

    return 0;
}