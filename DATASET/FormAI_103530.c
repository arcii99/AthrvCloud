//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>
#include <string.h>

void displayMenu(void);

int main(void)
{
    // Declare variables
    int choice;
    float num1, num2, result;
    char operation[10];

    // Display menu to user
    displayMenu();

    // Allow user to select operation
    printf("\nEnter your choice (1-8): ");
    scanf("%d", &choice);

    // Perform selected operation
    switch (choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("Sum of %.2f and %.2f is: %.2f\n", num1, num2, result);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("Difference of %.2f and %.2f is: %.2f\n", num1, num2, result);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("Product of %.2f and %.2f is: %.2f\n", num1, num2, result);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            if (num2 == 0)
            {
                printf("Error: Division by zero!\n");
            }
            else
            {
                result = num1 / num2;
                printf("Quotient of %.2f and %.2f is: %.2f\n", num1, num2, result);
            }
            break;

        case 5:
            printf("Enter a number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("Square root of %.2f is: %.2f\n", num1, result);
            break;

        case 6:
            printf("Enter a number: ");
            scanf("%f", &num1);
            result = pow(num1, 3.0);
            printf("Cube of %.2f is: %.2f\n", num1, result);
            break;

        case 7:
            printf("Enter an operation (+, -, *, /): ");
            scanf("%s", operation);
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            if (strcmp(operation, "+") == 0)
            {
                result = num1 + num2;
                printf("Sum of %.2f and %.2f is: %.2f\n", num1, num2, result);
            }
            else if (strcmp(operation, "-") == 0)
            {
                result = num1 - num2;
                printf("Difference of %.2f and %.2f is: %.2f\n", num1, num2, result);
            }
            else if (strcmp(operation, "*") == 0)
            {
                result = num1 * num2;
                printf("Product of %.2f and %.2f is: %.2f\n", num1, num2, result);
            }
            else if (strcmp(operation, "/") == 0)
            {
                if (num2 == 0)
                {
                    printf("Error: Division by zero!\n");
                }
                else
                {
                    result = num1 / num2;
                    printf("Quotient of %.2f and %.2f is: %.2f\n", num1, num2, result);
                }
            }
            else
            {
                printf("Invalid operation!\n");
            }
            break;

        case 8:
            printf("Exiting program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

// Function to display menu to user with options
void displayMenu(void)
{
    printf("Scientific Calculator Implementation\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Cube\n");
    printf("7. Custom Operation\n");
    printf("8. Exit\n");
}