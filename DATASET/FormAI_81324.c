//FormAI DATASET v1.0 Category: Calculator ; Style: peaceful
#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;

    printf("\nWelcome to the peaceful calculator!\n");
    printf("\nEnter the first number: ");
    scanf("%f", &num1);
    printf("\nEnter the operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("\nEnter the second number: ");
    scanf("%f", &num2);

    switch(operator){
        case '+':
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;
        case '/':
            if(num2 == 0){
                printf("Error! Cannot divide by zero.\n");
            }else{
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            }
            break;
        default:
            printf("Invalid operator!");
    }

    printf("\nThank you for using the peaceful calculator.\n");

    return 0;
}