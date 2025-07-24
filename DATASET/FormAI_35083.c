//FormAI DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for expense record
struct Expense {
    char date[20];
    char category[20];
    float amount;
};

int main() {
    struct Expense expenses[100]; // Array of expense records
    int num_expenses = 0; // Number of expenses recorded
    char input[20]; // User input for menu choice

    printf("Welcome to the Expense Tracker!\n");

    // Main menu loop
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. View expenses by category\n");
        printf("4. Exit\n");

        // Get menu choice
        printf("\nEnter your choice (1-4): ");
        fgets(input, 20, stdin);
        int choice = atoi(input);
        fflush(stdin);

        // Handle menu choice
        switch (choice) {
            case 1:
                // Add expense
                printf("\nEnter the date (MM/DD/YYYY): ");
                fgets(expenses[num_expenses].date, 20, stdin);
                printf("Enter the category: ");
                fgets(expenses[num_expenses].category, 20, stdin);
                printf("Enter the amount: $");
                fgets(input, 20, stdin);
                expenses[num_expenses].amount = atof(input);
                num_expenses++;
                printf("Expense added!\n");
                break;
            case 2:
                // View all expenses
                printf("\nDate\t\tCategory\tAmount\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%s\t%s\t\t$%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
                }
                break;
            case 3:
                // View expenses by category
                printf("\nEnter the category to view: ");
                fgets(input, 20, stdin);
                fflush(stdin);
                printf("\nDate\t\tAmount\n");
                for (int i = 0; i < num_expenses; i++) {
                    if (strcmp(expenses[i].category, input) == 0) {
                        printf("%s\t$%.2f\n", expenses[i].date, expenses[i].amount);
                    }
                }
                break;
            case 4:
                // Exit
                printf("\nGoodbye!\n");
                exit(0);
            default:
                // Invalid choice
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}