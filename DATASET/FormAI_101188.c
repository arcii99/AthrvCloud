//FormAI DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 10 // Maximum number of expenses that can be tracked

// Expense structure definition
typedef struct {
    char date[11];
    float amount;
    char category[20];
} expense;

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char user_input[20];
    int i;

    printf("Welcome to Expense Tracker!\n");
    printf("Enter your expenses below\n");

    while (1) { // Infinite loop until user chooses to exit
        // Prompt user to enter a new expense
        printf("Date (DD.MM.YYYY): ");
        fgets(expenses[num_expenses].date, sizeof(expenses[num_expenses].date), stdin);
        expenses[num_expenses].date[strcspn(expenses[num_expenses].date, "\n")] = '\0'; // Remove newline character
        printf("Amount (EUR): ");
        fgets(user_input, sizeof(user_input), stdin);
        expenses[num_expenses].amount = strtof(user_input, NULL);
        printf("Category: ");
        fgets(expenses[num_expenses].category, sizeof(expenses[num_expenses].category), stdin);
        expenses[num_expenses].category[strcspn(expenses[num_expenses].category, "\n")] = '\0'; // Remove newline character

        num_expenses++; // Increment number of expenses tracked

        if (num_expenses >= MAX_EXPENSES) { // Limit reached
            printf("\nMaximum number of expenses reached\n\n");
            break;
        }

        printf("\nEnter another expense (Y/N)? ");
        fgets(user_input, sizeof(user_input), stdin);

        if (user_input[0] == 'N' || user_input[0] == 'n') {
            break;
        }
    }

    // Print out all the tracked expenses
    printf("\nExpense Tracker Results:\n");
    printf("------------------------\n");

    for (i = 0; i < num_expenses; i++) {
        printf("Date: %s, Amount: %.2f EUR, Category: %s\n", expenses[i].date, expenses[i].amount, expenses[i].category);
    }

    return 0;
}