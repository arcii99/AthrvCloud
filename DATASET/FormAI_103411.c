//FormAI DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100

struct Expense {
    char description[50];
    float amount;
    time_t expense_time;
};

struct ExpenseTracker {
    struct Expense expenses[MAX_EXPENSES];
    int num_expenses;
};

void addExpense(struct ExpenseTracker *tracker, struct Expense expense)
{
    if (tracker->num_expenses < MAX_EXPENSES) {
        tracker->expenses[tracker->num_expenses++] = expense;
        printf("Added expense: %s $%.2f\n", expense.description, expense.amount);
    }
    else {
        printf("Cannot add more than %d expenses to tracker\n", MAX_EXPENSES);
    }
}

float getTotalExpenses(struct ExpenseTracker *tracker)
{
    float total = 0.0;
    for (int i = 0; i < tracker->num_expenses; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void printExpenses(struct ExpenseTracker *tracker)
{
    printf("Expense Tracker:\n");
    if (tracker->num_expenses == 0) {
        printf("No expenses have been added yet\n");
    }
    else {
        for (int i = 0; i < tracker->num_expenses; i++) {
            char time_buffer[26];
            struct tm* time_info = localtime(&tracker->expenses[i].expense_time);
            strftime(time_buffer, 26, "%Y-%m-%d %H:%M:%S", time_info);
            printf("[%s] %s $%.2f\n", time_buffer, tracker->expenses[i].description, tracker->expenses[i].amount);
        }
        printf("Total expenses: $%.2f\n", getTotalExpenses(tracker));
    }
}

int main()
{
    struct ExpenseTracker tracker = {0};

    // Add some expenses
    struct Expense expense1 = {"Groceries", 55.75, time(NULL)};
    addExpense(&tracker, expense1);

    struct Expense expense2 = {"Gas", 35.00, time(NULL)};
    addExpense(&tracker, expense2);

    // Print the expenses
    printExpenses(&tracker);

    // Add some more expenses
    struct Expense expense3 = {"Dinner", 42.50, time(NULL)};
    addExpense(&tracker, expense3);

    struct Expense expense4 = {"Movie tickets", 25.00, time(NULL)};
    addExpense(&tracker, expense4);

    // Print the expenses again
    printExpenses(&tracker);

    return 0;
}