//FormAI DATASET v1.0 Category: Arithmetic ; Style: bold
#include <stdio.h>

int main() {
    int num1, num2, result;
    char operator;
    
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);
    
    printf("Please enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);
    
    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("%d + %d = %d", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%d - %d = %d", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%d * %d = %d", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: divide by zero");
            } else {
                result = num1 / num2;
                printf("%d / %d = %d", num1, num2, result);
            }
            break;
        default:
            printf("Invalid operator");
    }
    
    return 0;
}