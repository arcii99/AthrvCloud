//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

struct budget{
    float income;
    float expenses;
    float savings;
};

void updateBudget(struct budget *budget) {
    float totalExpenses = 0;
    float expenses;
    printf("Enter current expenses or -1 to stop: ");
    scanf("%f", &expenses);
    while (expenses != -1) {
        totalExpenses += expenses;
        printf("Enter current expenses or -1 to stop: ");
        scanf("%f", &expenses);
    }
    budget->expenses = totalExpenses;
    budget->savings = budget->income - budget->expenses;
}

int main() {
    struct budget Luke;

    printf("Enter total income: ");
    scanf("%f", &Luke.income);
    updateBudget(&Luke);

    printf("\nLuke's Personal Finance Planner\n");
    printf("=================================\n");
    printf("Total Income: $%.2f\n", Luke.income);
    printf("Total Expenses: $%.2f\n", Luke.expenses);
    printf("Total Savings: $%.2f\n", Luke.savings);

    return 0;
}