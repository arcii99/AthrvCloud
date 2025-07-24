//FormAI DATASET v1.0 Category: Calculator ; Style: happy
#include <stdio.h>

int main() {
    printf("Hi, welcome to my happy calculator program!\n");
    printf("Let's do some happy calculations together!\n\n");

    float num1, num2, result;
    char op;

    printf("Please enter your first happy number: ");
    scanf("%f", &num1);

    printf("Please enter your second happy number: ");
    scanf("%f", &num2);

    printf("Which happy operation would you like to perform? (+, -, *, /): ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            result = num1 + num2;
            printf("\nYay! The happy result of %0.2f + %0.2f is: %0.2f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("\nYay! The happy result of %0.2f - %0.2f is: %0.2f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("\nYay! The happy result of %0.2f * %0.2f is: %0.2f\n", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("\nOh no! We can't divide by zero, that's not happy! Try again.\n");
            } else {
                result = num1 / num2;
                printf("\nYay! The happy result of %0.2f / %0.2f is: %0.2f\n", num1, num2, result);
            }
            break;
        default:
            printf("\nOh no! That operation is not a happy one, please try again.\n");
            break;
    }

    printf("\nThank you for using my happy calculator program! Have a happy day!\n");

    return 0;
}