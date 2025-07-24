//FormAI DATASET v1.0 Category: Arithmetic ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Declaration of all the variables
    int num1, num2, result, choice;
    char opt;

    do {
        // Main menu of the Program
        printf("Welcome to the Math Program\n");
        printf("Please select an option below:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Taking Input from the User
        scanf("%d", &choice);

        // Switch case block for all the operations
        switch(choice) {
            case 1: // Addition
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                result = num1 + num2;
                printf("The result of %d + %d is %d\n", num1, num2, result);
                break;

            case 2: // Subtraction
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                result = num1 - num2;
                printf("The result of %d - %d is %d\n", num1, num2, result);
                break;

            case 3: // Multiplication
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                result = num1 * num2;
                printf("The result of %d * %d is %d\n", num1, num2, result);
                break;

            case 4: // Division
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);

                // Checking if the divisor is zero
                if(num2 == 0) {
                    printf("Error: Division by Zero\n");
                }
                else {
                    result = num1 / num2;
                    printf("The result of %d / %d is %d\n", num1, num2, result);
                }
                break;

            case 5: // Exit
                printf("Quitting the Program\n");
                exit(0);
                break;

            default: // Invalid choice
                printf("Invalid Choice\n");
                break;
        }

        // Prompting the User to continue or not
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &opt);

    } while(opt == 'y' || opt == 'Y');

    return 0;
}