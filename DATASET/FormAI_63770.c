//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //Variables declaration
    char operator;
    double num1, num2, result;

    //Instructions for user input
    printf("Enter an operator (+, -, *, /, ^, %%): ");
    scanf("%c", &operator);
    printf("Enter two numbers separated by a space: ");
    scanf("%lf %lf", &num1, &num2);

    switch(operator){
        //Addition operator
        case '+':
            result = num1 + num2;
            break;
        //Subtraction operator
        case '-':
            result = num1 - num2;
            break;
        //Multiplication operator
        case '*':
            result = num1 * num2;
            break;
        //Division operator
        case '/':
            if(num2 == 0){ //If denominator is zero
                printf("Error: Division by zero.\n");
                exit(0); //Terminate program
            }
            result = num1 / num2;
            break;
        //Exponentiation operator
        case '^':
            result = pow(num1, num2);
            break;
        //Modulus operator
        case '%':
            result = fmod(num1, num2);
            break;
        //If invalid operator is entered
        default:
            printf("Error: Invalid operator.\n");
            exit(0); //Terminate program
    }

    //Display result to user
    printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);

    return 0;
}