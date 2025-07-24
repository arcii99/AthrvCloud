//FormAI DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to the post-apocalyptic calculator! \n\n");

    int choice, num1, num2;

    do {
        printf("Choose your operation: \n");
        printf("1. Add \n");
        printf("2. Subtract \n");
        printf("3. Multiply \n");
        printf("4. Divide \n");
        printf("5. Quit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter two numbers to add: \n");
                scanf("%d%d", &num1, &num2);
                printf("Result = %d\n", num1 + num2);
                break;

            case 2:
                printf("\nEnter two numbers to subtract: \n");
                scanf("%d%d", &num1, &num2);
                printf("Result = %d\n", num1 - num2);
                break;

            case 3:
                printf("\nEnter two numbers to multiply: \n");
                scanf("%d%d", &num1, &num2);
                printf("Result = %d\n", num1 * num2);
                break;

            case 4:
                printf("\nEnter two numbers to divide: \n");
                scanf("%d%d", &num1, &num2);
                if(num2 == 0) {
                    printf("Cannot divide by zero! The world has already ended, do not push your luck...\n");
                    break;
                }
                printf("Result = %d\n", num1 / num2);
                break;

            case 5:
                printf("\nThank you for using the post-apocalyptic calculator! Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}