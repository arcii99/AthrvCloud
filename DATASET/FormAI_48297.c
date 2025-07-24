//FormAI DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>

// initialize variables
float budget;
float expense;
char category[20];
int counter = 1;

int main() {
    // prompt user for budget input
    printf("Enter budget for the month: ");
    scanf("%f", &budget);

    // prompt user for expenses input
    while (expense != -1) {
        printf("\nEnter expense #%d (enter -1 to finish): ", counter);
        scanf("%f", &expense);
        if (expense != -1) {
            // prompt user for category input
            printf("Enter category: ");
            scanf("%s", category);
            // validate expense is within budget
            if (budget < expense) {
                printf("\n WARNING: Expense is over budget.");
            }
            // output expense details
            printf("\nExpense #%d: $%.2f for %s\n", counter, expense, category);
            counter++;
        }
    }
    // output budget and total expenses
    printf("\nYour budget: $%.2f", budget);
    printf("\nTotal expenses: $%.2f", expense);
    if (expense > budget) {
        printf("\nYou are over budget by $%.2f\n", (expense - budget));
    } else if (expense < budget) {
        printf("\nYou are under budget by $%.2f\n", (budget - expense));
    } else {
        printf("\nYou have met your budget.\n");
    }
    return 0;
}