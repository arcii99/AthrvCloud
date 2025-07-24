//FormAI DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>

int main() {
    int num_1, num_2, result;
    char operator;

    printf("\nWelcome to Energize Your Math!\n");
    printf("Enter your first number: ");
    scanf("%d", &num_1);

    printf("Enter your second number: ");
    scanf("%d", &num_2);

    printf("Enter an operator (+,-,*,/): ");
    scanf(" %c", &operator);

    switch(operator) {
        case '+':
            result = num_1 + num_2;
            printf("\n%d + %d = %d\n", num_1, num_2, result);
            break;
        case '-':
            result = num_1 - num_2;
            printf("\n%d - %d = %d\n", num_1, num_2, result);
            break;
        case '*':
            result = num_1 * num_2;
            printf("\n%d * %d = %d\n", num_1, num_2, result);
            break;
        case '/':
            if (num_2 == 0) {
                printf("\nError: division by zero\n");
            } else {
                result = num_1 / num_2;
                printf("\n%d / %d = %d\n", num_1, num_2, result);
            }
            break;
        default:
            printf("\nError: invalid operator\n");
    }

    return 0;
}