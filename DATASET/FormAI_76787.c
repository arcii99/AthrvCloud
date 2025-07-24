//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Ada Lovelace
/* This program demonstrates C Syntax Parsing */

#include <stdio.h>

int main() {

    /* Declare variables */
    int number;
    char operator, equals;

    /* Ask user to input a simple expression */
    printf("Enter a simple expression in the form of 'number operator equals': ");
    scanf("%d %c %c", &number, &operator, &equals);

    /* Parse the input */
    switch(operator) {
        case '+':
            printf("%d + %d = %d", number, equals - '0', number + (equals - '0'));
            break;
        case '-':
            printf("%d - %d = %d", number, equals - '0', number - (equals - '0'));
            break;
        case '*':
            printf("%d * %d = %d", number, equals - '0', number * (equals - '0'));
            break;
        case '/':
            printf("%d / %d = %.2f", number, equals - '0', (double)number / (double)(equals - '0'));
            break;
        default:
            printf("Invalid operator");
            break;
    }

    return 0;
}