//FormAI DATASET v1.0 Category: Calculator ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main(){
    char operator;
    double num1, num2;

    printf("Welcome to this Calculator program!\n\n");

    printf("Enter the operation (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter the First Number: ");
    scanf("%lf", &num1);

    printf("Enter the Second Number: ");
    scanf("%lf", &num2);

    switch(operator)
    {
        case '+':
            printf("%.2lf + %.2lf =  %.2lf", num1, num2, num1+num2);
            break;

        case '-':
            printf("%.2lf - %.2lf =  %.2lf", num1, num2, num1-num2);
            break;

        case '*':
            printf("%.2lf * %.2lf =  %.2lf", num1, num2, num1*num2);
            break;

        case '/':
            if(num2 == 0){
                printf("Cannot Divide by Zero!");
            }
            else{
                printf("%.2lf / %.2lf =  %.2lf", num1, num2, num1/num2);
            }
            break;

        default:
            printf("Invalid Operator");
    }

    printf("\n\nThank you for using this calculator program!");
    return 0;
}