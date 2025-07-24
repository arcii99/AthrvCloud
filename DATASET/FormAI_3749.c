//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Structure definition for expense items
struct expense {
    char name[50];
    float cost;
};

int main() {
    int numExpenses, i;
    float totalCost = 0;

    printf("Welcome to the Personal Finance Planner\n");

    // Prompt user for the number of expenses
    printf("How many expenses do you have this month? ");
    scanf("%d", &numExpenses);

    // Dynamically create an array of expenses
    struct expense *expenses = malloc(numExpenses * sizeof(struct expense));

    // Prompt user for the name and cost of each expense
    for (i = 0; i < numExpenses; i++) {
        printf("Enter expense %d name: ", i + 1);
        scanf("%s", expenses[i].name);

        printf("Enter expense %d cost: ", i + 1);
        scanf("%f", &expenses[i].cost);

        totalCost += expenses[i].cost;
    }

    // Display a summary of the expenses
    printf("\nExpense Summary\n");
    for (i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].cost);
    }

    printf("Total cost: $%.2f\n", totalCost);
    
    // Free dynamically allocated memory
    free(expenses);

    return 0;
}