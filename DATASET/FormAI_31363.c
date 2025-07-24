//FormAI DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 50

struct expense {
    char description[MAX_DESCRIPTION];
    float amount;
};

int main() {
    int numExpenses = 0;
    struct expense expenses[MAX_EXPENSES];
    float totalExpense = 0.0;
    char userInput[MAX_DESCRIPTION + 10];

    printf("Welcome to the Expense Tracker!\n");

    while (numExpenses < MAX_EXPENSES) {
        printf("Enter expense description (or 'quit' to exit): ");
        fgets(userInput, MAX_DESCRIPTION + 10, stdin);

        if (strcmp(userInput, "quit\n") == 0) {
            break;
        }

        struct expense newExpense;

        strtok(userInput, "\n");
        strncpy(newExpense.description, userInput, MAX_DESCRIPTION);

        printf("Enter expense amount: ");
        fgets(userInput, MAX_DESCRIPTION + 10, stdin);

        newExpense.amount = atof(userInput);

        expenses[numExpenses] = newExpense;
        numExpenses++;

        totalExpense += newExpense.amount;

        printf("Expense added!\n");
    }

    printf("Total expenses: $%.2f\n", totalExpense);

    for (int i = 0; i < numExpenses; i++) {
        printf("- %s ($%.2f)\n", expenses[i].description, expenses[i].amount);
    }

    printf("Thank you for using the Expense Tracker!");

    return 0;
}