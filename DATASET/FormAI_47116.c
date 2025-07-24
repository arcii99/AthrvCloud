//FormAI DATASET v1.0 Category: Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Calculator program!\n");
    printf("Please choose an operation to perform:\n");
    printf("+ for addition\n- for subtraction\n* for multiplication\n/ for division\n");
    char operation;
    scanf("%c", &operation);
    printf("You have chosen %c.\n", operation);

    int number1, number2;
    printf("Please enter the first number: ");
    scanf("%d", &number1);
    printf("Please enter the second number: ");
    scanf("%d", &number2);

    int result;
    switch(operation) {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            if(number2 == 0) {
                printf("Error: Division by zero.\n");
                exit(0);
            } else {
                result = number1 / number2;
            }
            break;
        default:
            printf("Error: Invalid operation.\n");
            exit(0);
    }

    printf("The result of your calculation is %d.\n", result);
    printf("Thanks for using the Calculator program! Come back soon!\n");

    return 0;
}