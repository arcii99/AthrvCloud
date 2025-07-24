//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("The sum of %d and %d is %d", num1, num2, result);
            break;
        
        case '-':
            result = num1 - num2;
            printf("%d minus %d is %d", num1, num2, result);
            break;
        
        case '*':
            result = num1 * num2;
            printf("%d multiplied by %d is %d", num1, num2, result);
            break;
        
        case '/':
            if(num2 == 0) {
                printf("Cannot divide by zero");
                break;
            }
            result = num1 / num2;
            printf("%d divided by %d is %d", num1, num2, result);
            break;
        
        default:
            printf("Invalid operator");
    }

    return 0;
}