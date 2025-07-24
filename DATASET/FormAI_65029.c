//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    printf("Welcome to Finance Party! Please choose an option:\n");
    printf("1. Input monthly budget\n");
    printf("2. Input monthly expenses\n");
    printf("3. View personal finances\n");
    printf("4. View group finances\n");
    printf("5. Exit\n");
    scanf("%d", &choice);

    // options for each choice
    switch (choice)
    {
        case 1:
            // code for inputting monthly budget
            break;
        case 2:
            // code for inputting monthly expenses
            break;
        case 3:
            // code for viewing personal finances
            break;
        case 4:
            // code for viewing group finances
            break;
        case 5:
            printf("Thank you for using Finance Party!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}