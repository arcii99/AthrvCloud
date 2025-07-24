//FormAI DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the expense details
struct Expense {
    char name[20];
    float amount;
    char date[12];
    char category[10];
};

int main() {
    int numExpenses, i, choice;
    float totalAmount = 0;
    char categoryInput[10];

    printf("Welcome to the Expense Tracker!\n\n");
    printf("How many expenses do you want to enter? ");
    scanf("%d", &numExpenses);

    struct Expense expenses[numExpenses];

    // Enter expense details
    for (i = 0; i < numExpenses; i++) {
        printf("\nExpense %d\n", i+1);
        printf("Enter expense name: ");
        scanf("%s", expenses[i].name);
        printf("Enter expense amount: ");
        scanf("%f", &expenses[i].amount);
        printf("Enter date of expense (DD-MM-YYYY): ");
        scanf("%s", expenses[i].date);
        printf("Enter expense category: ");
        scanf("%s", expenses[i].category);

        // Add expense amount to total amount
        totalAmount += expenses[i].amount;
    }

    // Display total expenses
    printf("\n-----------\n");
    printf("Total Expenses: $%.2f\n\n", totalAmount);

    // Display options for further analysis
    printf("What would you like to do?\n");
    printf("1. View expenses by category\n");
    printf("2. View expenses by date\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // View expenses by category
            printf("\nEnter category to view expenses: ");
            scanf("%s", categoryInput);

            printf("\nExpenses for category '%s':\n\n", categoryInput);
            printf("Expense Name\t Amount\t\t Date\n");
            printf("----------------------------------------------\n");

            for (i = 0; i < numExpenses; i++) {
                if (strcmp(expenses[i].category, categoryInput) == 0) {
                    printf("%s\t\t $%.2f\t\t %s\n", expenses[i].name, expenses[i].amount, expenses[i].date);
                }
            }
            break;

        case 2:
            // View expenses by date
            printf("\nEnter date to view expenses (DD-MM-YYYY): ");
            scanf("%s", categoryInput);

            printf("\nExpenses for date '%s':\n\n", categoryInput);
            printf("Expense Name\t Amount\t\t Category\n");
            printf("----------------------------------------------\n");

            for (i = 0; i < numExpenses; i++) {
                if (strcmp(expenses[i].date, categoryInput) == 0) {
                    printf("%s\t\t $%.2f\t\t %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                }
            }
            break;

        case 3:
            // Exit program
            printf("\nThanks for using the Expense Tracker!\n");
            break;

        default:
            printf("\nInvalid choice!\n");
            break;
    }

    return 0;
}