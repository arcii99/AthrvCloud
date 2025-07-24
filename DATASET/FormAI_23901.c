//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: creative
#include <stdio.h>
#include <math.h>

#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4
#define POWER 5
#define SQUARE_ROOT 6
#define EXIT_PROGRAM 7

void printMenu() {
    printf("Welcome to the Scientific Calculator\n\n");
    printf("Available Operations:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Exit the Program\n\n");
}

int main() {
    int operation, num1, num2;
    float result;

    do {
        printMenu();
        printf("Choose an operation: ");
        scanf("%d", &operation);

        switch(operation) {
            case ADDITION:
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                result = num1 + num2;
                printf("The result of %d + %d is %.2f\n\n", num1, num2, result);
                break;

            case SUBTRACTION:
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                result = num1 - num2;
                printf("The result of %d - %d is %.2f\n\n", num1, num2, result);
                break;

            case MULTIPLICATION:
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                result = num1 * num2;
                printf("The result of %d * %d is %.2f\n\n", num1, num2, result);
                break;

            case DIVISION:
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                result = (float)num1 / num2;
                printf("The result of %d / %d is %.2f\n\n", num1, num2, result);
                break;

            case POWER:
                printf("Enter the base number: ");
                scanf("%d", &num1);
                printf("Enter the exponent: ");
                scanf("%d", &num2);
                result = pow(num1, num2);
                printf("The result of %d^%d is %.2f\n\n", num1, num2, result);
                break;

            case SQUARE_ROOT:
                printf("Enter the number: ");
                scanf("%d", &num1);
                result = sqrt(num1);
                printf("The square root of %d is %.2f\n\n", num1, result);
                break;

            case EXIT_PROGRAM:
                printf("Goodbye! Thanks for using the Scientific Calculator!\n");
                break;

            default:
                printf("Invalid Operation! Please choose from the available options.\n\n");
                break;
        }

    } while(operation != EXIT_PROGRAM);

    return 0;
}