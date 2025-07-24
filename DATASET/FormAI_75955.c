//FormAI DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char name[50];
    double cost;
};

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    printf("Welcome to the Expense Tracker!\n\n");

    while (1) {
        printf("Enter the name of the expense (or 'done' to stop): ");
        scanf("%s", expenses[numExpenses].name);

        if (strcmp(expenses[numExpenses].name, "done") == 0) {
            break;
        }

        printf("Enter the cost of the expense: ");
        scanf("%lf", &expenses[numExpenses].cost);

        numExpenses++;
    }

    printf("\nExpenses:\n");

    double totalCost = 0.0;

    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2lf\n", expenses[i].name, expenses[i].cost);
        totalCost += expenses[i].cost;
    }

    printf("\nTotal: $%.2lf\n", totalCost);

    return 0;
}