//FormAI DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Ultimate Expense Tracker v1.0!\n");
    printf("Keeping track of your expenses has never been so exciting!\n");

    float budget, expense, totalExpenses = 0;
    int i = 1;

    printf("\nEnter your monthly budget: ");
    scanf("%f", &budget);

    while (i <= 5) {
        printf("\nEnter expense #%d: ", i);
        scanf("%f", &expense);

        if (expense > budget) {
            printf("Oops, you've exceeded your monthly budget!\n");
            expense = budget;
            printf("The expense has been adjusted to %0.2f\n", expense);
        }

        totalExpenses += expense;
        printf("Total expenses so far: %0.2f\n", totalExpenses);
        i++;
    }

    float remainingBudget = budget - totalExpenses;
    if (remainingBudget > 0) {
        printf("\nCongratulations! You still have %0.2f leftover!\n", remainingBudget);
    } else if (remainingBudget == 0) {
        printf("\nWow, you used up your entire budget!\n");
    } else {
        printf("\nUh-oh, you've overspent by %0.2f! Time to start saving up.\n", remainingBudget * -1);
    }

    printf("\nThank you for using the Ultimate Expense Tracker v1.0! Hope you enjoyed the ride.\n");

    return 0;
}