//FormAI DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#define MAX_EXPENSES 100

struct Expense {
    char name[50];
    float amount;
};
typedef struct Expense Expense;

float getTotalExpense(Expense expenses[], int length);

int main() {
    Expense expenses[MAX_EXPENSES];
    int i, numExpenses;
    float totalExpenses;

    printf("Enter the number of expenses: ");
    scanf("%d", &numExpenses);

    for(i=0; i<numExpenses; i++) {
        printf("Expense #%d name: ", i+1);
        scanf("%s", expenses[i].name);
        printf("Expense #%d amount: $", i+1);
        scanf("%f", &expenses[i].amount);
    }

    totalExpenses = getTotalExpense(expenses, numExpenses);

    printf("\n\nTotal expenses: $%.2f", totalExpenses);

    return 0;
}

float getTotalExpense(Expense expenses[], int length) {
    int i;
    float total = 0.0;

    for(i=0; i<length; i++) {
        total += expenses[i].amount;
    }

    return total;
}