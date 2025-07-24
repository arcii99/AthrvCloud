//FormAI DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char description[100];
    double amount;
    Date date;
} Expense;

int main() {
    int numExpenses;
    printf("How many expenses would you like to track? ");
    scanf("%d", &numExpenses);
    Expense* expenses = (Expense*) malloc(numExpenses * sizeof(Expense));

    for(int i = 0; i < numExpenses; i++) {
        printf("\nExpense %d:\n", i+1);
        printf("Description: ");
        scanf("%s", expenses[i].description);
        printf("Amount: $");
        scanf("%lf", &expenses[i].amount);
        printf("Date (day month year): ");
        scanf("%d %d %d", &expenses[i].date.day, &expenses[i].date.month, &expenses[i].date.year);
    }

    double totalExpenses = 0;
    printf("\n\n===== EXPENSE TRACKER =====\n");
    for(int i = 0; i < numExpenses; i++) {
        printf("\nExpense %d:\n", i+1);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: $%.2lf\n", expenses[i].amount);
        printf("Date: %d/%d/%d\n", expenses[i].date.month, expenses[i].date.day, expenses[i].date.year);
        totalExpenses += expenses[i].amount;
    }
    printf("\nTotal Expenses: $%.2lf\n", totalExpenses);

    free(expenses);
    return 0;
}