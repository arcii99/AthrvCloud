//FormAI DATASET v1.0 Category: Expense Tracker ; Style: inquisitive
#include <stdio.h>

struct Expense {
    char name[50];
    double amount;
};

int main() {
    int numExpenses;
    printf("How many expenses do you want to track? ");
    scanf("%d", &numExpenses);

    struct Expense expenses[numExpenses];

    for (int i = 0; i < numExpenses; i++) {
        printf("\n---- Expense #%d ----\n", i + 1);
        printf("Name: ");
        scanf("%s", expenses[i].name);
        printf("Amount: $");
        scanf("%lf", &expenses[i].amount);
    }

    printf("\n\n----- Expense Report -----\n");
    double totalExpense = 0;
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2lf\n", expenses[i].name, expenses[i].amount);
        totalExpense += expenses[i].amount;
    }
    printf("--------------------------\n");
    printf("Total Expenses: $%.2lf", totalExpense);

    return 0;
}