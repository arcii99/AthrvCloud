//FormAI DATASET v1.0 Category: Calculator ; Style: relaxed
#include <stdio.h>

int main() {
    char op;
    int num1, num2, result;
    
    printf("Please enter the math operation(+, -, *, /): ");
    scanf("%c", &op);
    
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    
    printf("Please enter the second number: ");
    scanf("%d", &num2);
    
    switch(op) {
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
                printf("Error: Cannot divide by zero");
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