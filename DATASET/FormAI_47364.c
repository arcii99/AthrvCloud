//FormAI DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice = 0, amount = 0, total_expenses = 0;
    char date[30], category[30];

    printf("Welcome to the Expense Tracker Program!\n\n");
    while (choice != 4) {
        printf("What would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. View total expenses\n");
        printf("3. View expenses by category\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the date of the expense (mm/dd/yyyy): ");
                scanf("%s", date);
                printf("Enter the category of the expense: ");
                scanf("%s", category);
                printf("Enter the amount of the expense: ");
                scanf("%d", &amount);
                total_expenses += amount;
                printf("Expense successfully added!\n\n");
                break;
            case 2:
                printf("Total expenses: $%d\n\n", total_expenses);
                break;
            case 3:
                printf("Enter the category to view expenses: ");
                scanf("%s", category);
                printf("Expenses for category %s:\n", category);
                // list all expenses for this category
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}