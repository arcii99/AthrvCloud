//FormAI DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

struct ExpenseTracker {
    char *category;
    float amount;
};

int main() {
    int numOfExpenses;
    float totalExpenses = 0.0;

    printf("Welcome to the Expense Tracker!\n");
    printf("How many expenses would you like to track today? ");
    scanf("%d", &numOfExpenses);

    struct ExpenseTracker expenses[numOfExpenses];

    for (int i = 0; i < numOfExpenses; i++) {
        expenses[i].category = (char *) malloc(20 * sizeof(char));
        printf("\nEnter expense category: ");
        scanf("%s", expenses[i].category);
        printf("Enter expense amount: $");
        scanf("%f", &expenses[i].amount);
        totalExpenses += expenses[i].amount;
    }

    printf("\n**************************\n");
    printf("EXPENSE TRACKER\n");
    printf("**************************\n");

    for (int i = 0; i < numOfExpenses; i++) {
        printf("%s      $%.2f\n", expenses[i].category, expenses[i].amount);
    }

    printf("\nTotal expenses: $%.2f\n", totalExpenses);

    for (int i = 0; i < numOfExpenses; i++) {
        free(expenses[i].category);
    }

    return 0;
}