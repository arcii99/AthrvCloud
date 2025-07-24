//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include<stdio.h>
#include<math.h> //for mathematical functions

int main(){
    char operator;
    double num1, num2, result; //double for decimal input/output
    
    printf("Enter operator (+, -, *, /, ^, sqrt):");
    scanf("%c", &operator); //input operator

    switch(operator)
    {
        case '+':
            printf("Enter two operands to add:");
            scanf("%lf %lf",&num1, &num2); //input two operands
            result = num1 + num2; //addition operation
            printf("%.2lf + %.2lf = %.2lf",num1, num2, result);
            break;
        case '-':
            printf("Enter two operands to subtract:");
            scanf("%lf %lf",&num1, &num2); //input two operands
            result = num1 - num2; //subtraction operation
            printf("%.2lf - %.2lf = %.2lf",num1, num2, result);
            break;
        case '*':
            printf("Enter two operands to multiply:");
            scanf("%lf %lf",&num1, &num2); //input two operands
            result = num1 * num2; //multiplication operation
            printf("%.2lf * %.2lf = %.2lf",num1, num2, result);
            break;
        case '/':
            printf("Enter two operands to divide:");
            scanf("%lf %lf",&num1, &num2); //input two operands
            if(num2 == 0){ //check for divide by zero error
                printf("Error: cannot divide by zero");
                break;
            }
            result = num1 / num2; //division operation
            printf("%.2lf / %.2lf = %.2lf",num1, num2, result);
            break;
        case '^':
            printf("Enter base and exponent to find power (base^exponent):");
            scanf("%lf %lf",&num1, &num2); //input base and exponent
            result = pow(num1, num2); //power function from math.h
            printf("%.2lf ^ %.2lf = %.2lf",num1, num2, result);
            break;
        case 's':
            printf("Enter value to find square root:");
            scanf("%lf",&num1); //input value to find square root
            result = sqrt(num1); //square root function from math.h
            printf("sqrt(%.2lf) = %.2lf", num1, result);
            break;
        default:
            printf("Invalid operator");
    }
    return 0; //program executed successfully
}