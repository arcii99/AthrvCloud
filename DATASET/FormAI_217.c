//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
// Get ready for some amazing arithmetic magic!
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Are you ready for some math fun?! Let's go!\n\n");

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("\n\nSelect an operator to perform the calculation:\n");
    printf("(+) Addition\n(-) Subtraction\n(*) Multiplication\n(/) Division\n");
    scanf(" %c", &operator);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("\n\nWooohoooo! You got it! %d + %d = %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("\n\nBam! Just like that! %d - %d = %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("\n\nGenius!! %d * %d = %d\n", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("\n\nOops! You can't divide by zero, silly. Try again.\n");
            }
            else {
                result = num1 / num2;
                printf("\n\nIncredible! %d / %d = %d\n", num1, num2, result);
            }
            break;
        default:
            printf("\n\nUh oh, you picked an invalid operator. Try again.\n");
    }

    printf("\n\nThanks for playing! Come back soon for more math adventures.\n");

    return 0;
}