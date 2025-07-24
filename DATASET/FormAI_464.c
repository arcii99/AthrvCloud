//FormAI DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>

#define MAX_EXPENSES 100

int main() {
    float expenses[MAX_EXPENSES];  // maximum number of expenses that can be tracked
    float totalExpenses = 0.0;
    int numExpenses = 0;
    int i;

    printf("Welcome to the Expense Tracker Program\n\n");

    // loop to get expenses from user
    while (1) {
        float expense;
        printf("Enter an expense (or -1 to stop): ");
        scanf("%f", &expense);

        if (expense == -1) {
            break;
        }

        // add expense to array
        if (numExpenses < MAX_EXPENSES) {
            expenses[numExpenses++] = expense;
            totalExpenses += expense;
        } else {
            printf("Maximum number of expenses reached\n");
            break;
        }
    }

    printf("\nExpenses:\n");

    // loop to print expenses
    for (i = 0; i < numExpenses; i++) {
        printf("$%.2f\n", expenses[i]);
    }

    printf("Total expenses: $%.2f\n", totalExpenses);

    return 0;
}