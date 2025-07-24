//FormAI DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>

int main() {
    int num1, num2;
    char operator;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    switch(operator) {
        case '+':
            printf("%d + %d = %d", num1, num2, num1+num2);
            break;
        case '-':
            printf("%d - %d = %d", num1, num2, num1-num2);
            break;
        case '*':
            printf("%d * %d = %d", num1, num2, num1*num2);
            break;
        case '/':
            if(num2 == 0) {
                printf("Cannot divide by zero");
            } else {
                printf("%d / %d = %d", num1, num2, num1/num2);
            }
            break;
        default:
            printf("Invalid operator");
            break;
    }

    return 0;
}