//FormAI DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    char operator;

    printf("Greetings user! Let's do some arithmetic!\n");
    printf("Please input the first number: ");
    scanf("%d", &num1);
    printf("Please input the operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Please input the second number: ");
    scanf("%d", &num2);

    if(operator == '+') {
        printf("%d + %d = %d\n", num1, num2, num1+num2);
    } else if(operator == '-') {
        printf("%d - %d = %d\n", num1, num2, num1-num2);
    } else if(operator == '*') {
        printf("%d * %d = %d\n", num1, num2, num1*num2);
    } else if(operator == '/') {
        if(num2 == 0) {
            printf("Error: Division by zero\n");
            exit(0);
        }
        printf("%d / %d = %d\n", num1, num2, num1/num2);
    } else {
        printf("Error: Unknown operator\n");
        exit(0);
    }

    printf("Thanks for using this arithmetic calculator.\n");
    return 0;
}