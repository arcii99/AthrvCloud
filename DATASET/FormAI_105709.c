//FormAI DATASET v1.0 Category: Arithmetic ; Style: portable
#include<stdio.h>

int main(){
    int num1, num2, result;
    char operator;

    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("Enter second number: ");
    scanf("%d",&num2);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c",&operator);

    switch(operator){
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
        default:
            printf("Invalid operator");
    }

    printf("%d %c %d = %d",num1,operator,num2,result);

    return 0;
}