//FormAI DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include<stdio.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Enter the first integer:");
    scanf("%d",&num1);

    printf("Enter operator (+,-,*,/):");
    scanf(" %c",&operator);

    // Input validation
    if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
        printf("Invalid operator.\n");
        return 1;
    }

    printf("Enter the second integer:");
    scanf("%d",&num2);

    // Division by zero paranoia
    if (operator == '/' && num2 == 0) {
        printf("Cannot divide by zero.\n");
        return 1;
    }

    // Arithmetic calculations
    if (operator == '+') {
        result = num1 + num2;
    } else if (operator == '-') {
        result = num1 - num2;
    } else if (operator == '*') {
        result = num1 * num2;
    } else {
        result = num1 / num2;
    }

    // Result validation paranoia
    if ((num1 < 0 && num2 < 0 && result >= 0) || (num1 > 0 && num2 > 0 && result <= 0)) {
        printf("Arithemtic overflow: result exceeds limits of type int.\n");
        return 1;
    }

    printf("Result: %d\n",result);

    return 0;
}