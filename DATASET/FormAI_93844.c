//FormAI DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Structure to hold expense information
struct Expense {
    char date[11];
    char category[50];
    char description[100];
    float cost;
};

// Function prototypes
void addExpense(struct Expense[], int*);
void printExpenses(struct Expense[], int);
int getExpenseIndexByCategory(struct Expense[], int, char*);
void printCategorySummary(struct Expense[], int, char*);

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int userInput = 0;

    while(userInput != 4) {
        // Display menu
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. View Category Summary\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &userInput);

        switch(userInput) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                printExpenses(expenses, numExpenses);
                break;
            case 3:
                char category[50];
                printf("Enter category: ");
                scanf("%s", category);
                printCategorySummary(expenses, numExpenses, category);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
    }

    return 0;
}

void addExpense(struct Expense expenses[], int *numExpenses) {
    if(*numExpenses == MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached!\n");
        return;
    }

    // Prompt user for expense information
    printf("Enter expense date (MM/DD/YYYY): ");
    scanf("%s", expenses[*numExpenses].date);
    printf("Enter expense category: ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Enter expense description: ");
    scanf("%s", expenses[*numExpenses].description);
    printf("Enter expense cost: ");
    scanf("%f", &expenses[*numExpenses].cost);

    (*numExpenses)++;
}

void printExpenses(struct Expense expenses[], int numExpenses) {
    if(numExpenses == 0) {
        printf("No expenses to display!\n");
        return;
    }

    // Print table header
    printf("%-12s %-15s %-25s %s\n", "Date", "Category", "Description", "Cost");

    // Print each expense
    int i;
    for(i = 0; i < numExpenses; i++) {
        printf("%-12s %-15s %-25s $%.2f\n", expenses[i].date, expenses[i].category, expenses[i].description, expenses[i].cost);
    }
}

int getExpenseIndexByCategory(struct Expense expenses[], int numExpenses, char *category) {
    int i;
    for(i = 0; i < numExpenses; i++) {
        if(strcmp(expenses[i].category, category) == 0) {
            return i;
        }
    }

    return -1;
}

void printCategorySummary(struct Expense expenses[], int numExpenses, char *category) {
    int expenseIndex = getExpenseIndexByCategory(expenses, numExpenses, category);
    if(expenseIndex == -1) {
        printf("No expenses in category!\n");
        return;
    }

    float totalCost = 0;
    int numExpensesInCategory = 0;

    // Find all expenses in category and calculate total cost
    while(expenseIndex != -1) {
        totalCost += expenses[expenseIndex].cost;
        numExpensesInCategory++;
        expenseIndex = getExpenseIndexByCategory(expenses + expenseIndex + 1, numExpenses - expenseIndex - 1, category);
    }

    // Print summary
    printf("Category Summary for %s:\n", category);
    printf("Number of expenses: %d\n", numExpensesInCategory);
    printf("Total cost: $%.2f\n", totalCost);
}