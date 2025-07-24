//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char category[20];
    float amount;
};

int main() {
    int numExpenses;
    printf("Enter the number of expenses: ");
    scanf("%d", &numExpenses);

    struct Expense *expenses = calloc(numExpenses, sizeof(struct Expense));

    for(int i = 0; i < numExpenses; i++) {
        printf("Enter the category of expense %d: ", i+1);
        scanf("%s", (expenses+i)->category);
        printf("Enter the amount of expense %d: ", i+1);
        scanf("%f", &(expenses+i)->amount);
    }

    float total = 0;
    for(int i = 0; i < numExpenses; i++) {
        printf("Expense %d - Category: %s, Amount: $%.2f\n", i+1, (expenses+i)->category, (expenses+i)->amount);
        total += (expenses+i)->amount;
    }

    printf("Total Expenses: $%.2f\n", total);

    free(expenses);
    return 0;
}