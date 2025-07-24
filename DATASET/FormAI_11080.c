//FormAI DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>

int main() {
    int num1, num2;
    char operator;

    printf("Enter two integers separated by a space:");
    scanf("%d %d", &num1, &num2);

    printf("Enter an arithmetic operator (+, -, *, /):");
    scanf(" %c", &operator);

    switch(operator) {
        case '+':
            printf("%d + %d = %d", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%d - %d = %d", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%d * %d = %d", num1, num2, num1 * num2);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: division by zero");
            } else {
                printf("%d / %d = %.2f", num1, num2, (float)num1 / num2);
            }
            break;
        default:
            printf("Error: invalid operator");
    }
    
    return 0;
}