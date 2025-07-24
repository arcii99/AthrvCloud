//FormAI DATASET v1.0 Category: Arithmetic ; Style: retro
#include<stdio.h>
#include<stdlib.h>

int main(){

    printf("Retro Calculator\n");
    
    int num1, num2, result;
    char operator;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    printf("Select operation (+, -, *, /): ");
    scanf(" %c", &operator);

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
            if(num2 == 0){
                printf("Error: Cannot divide by zero!\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }
    
    printf("\nResult: %d\n", result);
    
    return 0;
    
}