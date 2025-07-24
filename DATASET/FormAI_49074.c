//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    double num1, num2, result;

    char op;

    printf("Welcome to the Scientific Calculator\n");

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /, ^): ");
    scanf(" %c", &op);

    if(op != '^'){ //Except for power operator, second number is required
      printf("Enter second number: ");
      scanf("%lf", &num2);
    }

    switch(op){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '^':
            result = pow(num1, num2);
            break;
        default:
            printf("Invalid operator");
            return EXIT_FAILURE;
    }

    printf("Result: %lf", result);
    
    return EXIT_SUCCESS;
}