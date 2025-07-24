//FormAI DATASET v1.0 Category: Calculator ; Style: synchronous
#include<stdio.h>
int main(){
    int num1, num2, result;
    char operator;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch(operator){
        case '+':
            result = num1 + num2;
            printf("Sum of %d and %d is: %d", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("Difference between %d and %d is: %d", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("Product of %d and %d is: %d", num1, num2, result);
            break;
        case '/':
            if(num2 == 0){
                printf("Error! Cannot divide by zero.");
            }
            else{
                result = num1 / num2;
                printf("Division of %d by %d is: %d", num1, num2, result);
            }
            break;
        default:
            printf("Invalid operator! Please enter a valid operator.");
    }

    return 0;
}