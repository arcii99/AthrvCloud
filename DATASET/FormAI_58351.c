//FormAI DATASET v1.0 Category: Arithmetic ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

#define ADDITION '+'
#define SUBTRACTION '-'
#define MULTIPLICATION '*'
#define DIVISION '/'
#define MODULO '%'

int main(){

    char operator;
    float number1, number2, result;

    printf("Enter an operator (+, -, *, /, %%) : ");
    scanf("%c", &operator);

    printf("Enter number1: ");
    scanf("%f", &number1);

    printf("Enter number2: ");
    scanf("%f", &number2);

    switch(operator) {
        case ADDITION:
            result = number1 + number2;
            break;

        case SUBTRACTION:
            result = number1 - number2;
            break;

        case MULTIPLICATION:
            result = number1 * number2;
            break;

        case DIVISION:
            if(number2 == 0){
                printf("Error! Cannot divide by zero.");
                exit(0);
            }
            result = number1 / number2;
            break;

        case MODULO:
            result = (int)number1 % (int)number2;
            break;

        default:
            printf("Error! Invalid operator.");
            exit(0);
    }

    printf("%.2f %c %.2f = %.2f", number1, operator, number2, result);

    return 0;
}