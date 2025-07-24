//FormAI DATASET v1.0 Category: Calculator ; Style: innovative
#include <stdio.h>

int main() {

    printf("********** Welcome to the C Calculator **********\n");

    char operation;
    double num1, num2;

    do {
        printf("\nEnter your desired operation (+, -, *, /) or press 'q' to quit: ");
        scanf(" %c", &operation);

        if (operation == 'q') {
            printf("\nThank you for using the C Calculator.\n");
            break;
        }

        printf("\nEnter your two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        switch(operation) {
            case '+':
                printf("\nSum is %.2lf\n", num1 + num2);
                break;
            case '-':
                printf("\nDifference is %.2lf\n", num1 - num2);
                break;
            case '*':
                printf("\nProduct is %.2lf\n", num1 * num2);
                break;
            case '/':
                if (num2 == 0) {
                    printf("\nError: Cannot divide by zero.\n");
                    break;
                }
                printf("\nQuotient is %.2lf\n", num1 / num2);
                break;
            default:
                printf("\nInvalid input. Please try again.\n");
        }
    } while (operation != 'q');

    return 0;
}