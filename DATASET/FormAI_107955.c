//FormAI DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char category[20];
    float amount;
};

int main() {
    int numExpenses, i;
    float totalAmount = 0;

    printf("Expense Tracker\n\n");

    printf("Enter the number of expenses: ");
    scanf("%d", &numExpenses);

    struct Expense expenses[numExpenses];

    for (i = 0; i < numExpenses; i++) {
        printf("\nEnter expense %d category: ", i + 1);
        scanf("%s", &expenses[i].category);

        printf("Enter expense %d amount: ", i + 1);
        scanf("%f", &expenses[i].amount);

        totalAmount += expenses[i].amount;
    }

    printf("\nExpense Summary:\n");
    printf("------------------\n");

    for (i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
    }

    printf("\nTotal: $%.2f\n", totalAmount);

    return 0;
}