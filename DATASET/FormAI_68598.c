//FormAI DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char name[50];
    double amount;
    char category[20];
};

void printExpenses(struct Expense* expenses, int numExpenses) {
    printf("\n\n%s\n", "------Expenses------");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2lf (%s)\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {

    int numExpenses = 0;
    struct Expense* expenses = (struct Expense*) malloc(sizeof(struct Expense));

    // Get expenses from user
    char input[20];
    printf("%s", "Enter expense name (or 'done' to stop adding expenses): ");
    scanf("%s", input);
    while (strcmp(input, "done")) {
        numExpenses++;
        expenses = (struct Expense*) realloc(expenses, numExpenses * sizeof(struct Expense));
        strcpy(expenses[numExpenses-1].name, input);

        printf("%s", "Enter expense amount: $");
        scanf("%lf", &expenses[numExpenses-1].amount);

        printf("%s", "Enter expense category: ");
        scanf("%s", expenses[numExpenses-1].category);

        printf("%s", "Enter expense name (or 'done' to stop adding expenses): ");
        scanf("%s", input);
    }

    // Print expenses
    printExpenses(expenses, numExpenses);

    // Free memory
    free(expenses);

    return 0;
}