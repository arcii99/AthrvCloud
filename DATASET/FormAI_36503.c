//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>

int main() {

    // initialize variables
    int num1, num2;
    float answer;
    char operator;

    printf("Enter an equation to be evaluated (example: 5+2.5): ");
    scanf("%d %c %f", &num1, &operator, &num2);

    switch (operator) {
        case '+':
            answer = num1 + num2;
            break;

        case '-':
            answer = num1 - num2;
            break;

        case '*':
            answer = num1 * num2;
            break;

        case '/':
            answer = (float)num1 / num2;
            break;

        default:
            printf("Invalid operator\n");
            return 1;
    }

    printf("The answer is: %.2f", answer);

    return 0;
}