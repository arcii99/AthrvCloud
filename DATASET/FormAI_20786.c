//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double calculate(char, double, double);                                                    // function prototype for calculator

int main()
{
    char operator;
    double num1, num2;
    printf("Enter an operator (+, -, *, /, ^, sqrt): ");
    scanf("%c", &operator);                                                              //user inputs operator
    if (operator != 'sqrt')                                                              //if statement to check for square root operation
    {
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);                                                    //user inputs two numbers
        printf("%.2lf %c %.2lf = %.2lf", num1, operator, num2, calculate(operator, num1, num2)); //output result of the calculation
    }
    else
    {
        printf("Enter a number: ");
        scanf("%lf", &num1);                                                              //user inputs single number for square root operation
        printf("sqrt(%.2lf) = %.2lf", num1, calculate(operator, num1, num2));            //output result of the square root operation
    }    
    return 0;
}

double calculate(char op, double num1, double num2)                                        //function to handle calculations
{
    double result;
    switch(op)
    {
        case '+': result=num1+num2; break;
        case '-': result=num1-num2; break;
        case '*': result=num1*num2; break;
        case '/': result=num1/num2; break;
        case '^': result=pow(num1,num2); break;
        case 'sqrt': result=sqrt(num1); break;
        default: printf("Error! Invalid operator"); exit(0);                               //if invalid operator is entered, close program
    }
    return result;
}