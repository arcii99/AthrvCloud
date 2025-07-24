//FormAI DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100 // Maximum number of expenses that can be tracked

struct Expense {
    float amount;
    char category[20];
    char description[50];
};

struct ExpenseTracker {
    int numExpenses;
    struct Expense expenses[MAX_EXPENSES];
    float totalExpenses;
};

// Function declarations
void addExpense(struct ExpenseTracker *);
void printExpenses(struct ExpenseTracker);
void printExpense(struct Expense);
float calculateTotalExpenses(int, struct Expense[]);
float calculateCategoryExpenses(char[], int, struct Expense[]);

int main() {
    struct ExpenseTracker tracker;
    tracker.numExpenses = 0;
    tracker.totalExpenses = 0;

    char choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. Print all expenses\n");
        printf("3. Print total expenses\n");
        printf("4. Calculate expenses by category\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");

        // Get user choice
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addExpense(&tracker);
                break;
            case '2':
                printExpenses(tracker);
                break;
            case '3':
                printf("\nTotal expenses: $%.2f\n", tracker.totalExpenses);
                break;
            case '4':
                char category[20];
                printf("\nEnter category: ");
                scanf("%s", category);
                printf("\nExpenses in category '%s': $%.2f\n", category, calculateCategoryExpenses(category, tracker.numExpenses, tracker.expenses));
                break;
            case '5':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != '5');

    return 0;
}

// Function to add a new expense to the tracker
void addExpense(struct ExpenseTracker *tracker) {
    if (tracker->numExpenses >= MAX_EXPENSES) {
        printf("\nExpense tracker is full.\n");
        return;
    }

    struct Expense newExpense;
    printf("\nEnter amount: ");
    scanf("%f", &newExpense.amount);
    printf("Enter category: ");
    scanf("%s", newExpense.category);
    printf("Enter description: ");
    scanf("%s", newExpense.description);

    tracker->expenses[tracker->numExpenses] = newExpense;
    tracker->numExpenses++;
    tracker->totalExpenses += newExpense.amount;

    printf("\nExpense added successfully.\n");
}

// Function to print all expenses in the tracker
void printExpenses(struct ExpenseTracker tracker) {
    if (tracker.numExpenses == 0) {
        printf("\nNo expenses to show.\n");
        return;
    }

    printf("\nAll expenses:\n");
    for (int i = 0; i < tracker.numExpenses; i++) {
        printExpense(tracker.expenses[i]);
    }
}

// Function to print a single expense
void printExpense(struct Expense e) {
    printf("- $%.2f | %s | %s\n", e.amount, e.category, e.description);
}

// Function to calculate the total expenses from all tracked expenses
float calculateTotalExpenses(int numExpenses, struct Expense expenses[]) {
    float sum = 0;
    for (int i = 0; i < numExpenses; i++) {
        sum += expenses[i].amount;
    }
    return sum;
}

// Function to calculate the total expenses for a given category
float calculateCategoryExpenses(char category[], int numExpenses, struct Expense expenses[]) {
    float sum = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(category, expenses[i].category) == 0) {
            sum += expenses[i].amount;
        }
    }
    return sum;
}