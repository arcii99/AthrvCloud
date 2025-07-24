//FormAI DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent expenses
typedef struct {
    char *category;
    double amount;
} Expense;

int main() {
    int num_expenses;
    printf("Welcome to your C Expense Tracker!\n\n");
    
    // Prompt user to enter number of expenses
    printf("How many expenses would you like to log? ");
    scanf("%d", &num_expenses);

    // Declare expenses array
    Expense expenses[num_expenses];
    
    // Loop through and prompt user to enter expenses
    for (int i = 0; i < num_expenses; i++) {
        expenses[i].category = malloc(20 * sizeof(char));
        printf("Enter expense category: ");
        scanf("%s", expenses[i].category);
        printf("Enter expense amount: ");
        scanf("%lf", &expenses[i].amount);
        printf("Expense logged!\n\n");
    }
    
    // Calculate total expenses and print report
    double total_expenses = 0;
    printf("-----------------------------\n");
    printf("     EXPENSE TRACKER REPORT\n");
    printf("-----------------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s $%.2lf\n", expenses[i].category, expenses[i].amount);
        total_expenses += expenses[i].amount;
        free(expenses[i].category);
    }
    printf("-----------------------------\n");
    printf("TOTAL EXPENSES: $%.2lf\n", total_expenses);

    return 0;
}