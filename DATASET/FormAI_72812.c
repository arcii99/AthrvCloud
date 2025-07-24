//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>

int main() {
    int firstNumber, secondNumber, result;
    char operator;

    printf("Welcome to the Fun Arithmetic Program!\n");
    printf("Please enter the first number: ");
    scanf("%d", &firstNumber);
    printf("Please enter the second number: ");
    scanf("%d", &secondNumber);
    printf("Please choose an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch (operator) {
        case '+':
            result = firstNumber + secondNumber;
            printf("Et voila! %d + %d = %d\n", firstNumber, secondNumber, result);
            break;
        case '-':
            result = firstNumber - secondNumber;
            printf("You can't handle the subtraction truth! %d - %d = %d\n", firstNumber, secondNumber, result);
            break;
        case '*':
            result = firstNumber * secondNumber;
            printf("Multiplying like a boss! %d * %d = %d\n", firstNumber, secondNumber, result);
            break;
        case '/':
            if (secondNumber == 0) {
                printf("Trying to divide by zero again? Shame on you!\n");
            } else {
                result = firstNumber / secondNumber;
                printf("Divide and conquer, baby! %d / %d = %d\n", firstNumber, secondNumber, result);
            }
            break;
        default:
            printf("Invalid operator. Try again, my friend!\n");
            break;
    }

    printf("Thank you for using the Fun Arithmetic Program! May all your calculations be hilarious!\n");

    return 0;
}