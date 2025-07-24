//FormAI DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the brave C Math exercise program!\n");

    // Declare variables
    int x, y, result;
    char operation;

    // Get user input
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
  
    // Perform the operation
    switch(operation)
    {
        case '+':
            result = x + y;
            printf("%d + %d = %d\n", x, y, result);
            break;
        case '-':
            result = x - y;
            printf("%d - %d = %d\n", x, y, result);
            break;
        case '*':
            result = x * y;
            printf("%d * %d = %d\n", x, y, result);
            break;
        case '/':
            if(y == 0)
            {
                printf("Cannot divide by zero!\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                result = x / y;
                printf("%d / %d = %d\n", x, y, result);
            }
            break;
        default:
            printf("Invalid operation entered!\n");
            exit(EXIT_FAILURE);
    }

    printf("Thank you for using the brave C Math exercise program!\n");

    return 0;
}