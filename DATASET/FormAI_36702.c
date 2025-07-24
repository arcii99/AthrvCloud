//FormAI DATASET v1.0 Category: Educational ; Style: brave
#include <stdio.h>

int main() {
    printf("Welcome to the Brave Camp!\n");

    int num1 = 0, num2 = 0, result = 0;
    char operator;

    printf("Enter a simple arithmetic expression (ex. 2 + 3): ");
    scanf("%d %c %d", &num1, &operator, &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator!\n");
    }

    printf("The answer is: %d\n", result);

    printf("You have completed the Brave Camp. Congratulations!\n");

    return 0;
}