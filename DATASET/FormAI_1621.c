//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    double x, y, result;
    char operator;

    printf("Enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operator);

    printf("Enter two operands: ");
    scanf("%lf %lf", &x, &y);

    switch(operator){
        case '+':
            result = x + y;
            printf("%.2lf + %.2lf = %.2lf", x, y, result);
            break;
        
        case '-':
            result = x - y;
            printf("%.2lf - %.2lf = %.2lf", x, y, result);
            break;
        
        case '*':
            result = x * y;
            printf("%.2lf * %.2lf = %.2lf", x, y, result);
            break;

        case '/':
            if (y == 0){
                printf("Undefined");
            }
            else{
                result = x / y;
                printf("%.2lf / %.2lf = %.2lf", x, y, result);
            }
            break;

        case '^':
            result = pow(x, y);
            printf("%.2lf ^ %.2lf = %.2lf", x, y, result);
            break;

        default:
            printf("Invalid operator selected");
            break;
    }
    return 0;
}