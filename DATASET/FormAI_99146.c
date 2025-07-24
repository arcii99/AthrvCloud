//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the Personal Finance Planner! Let's get started.\n");

    float income;
    printf("Please enter your monthly income: $");
    scanf("%f", &income);

    float expenses = 0;
    int numExpenses;
    printf("How many monthly expenses do you have?");
    scanf("%d", &numExpenses);

    for (int i = 1; i <= numExpenses; i++) {
        float expense;
        printf("Enter expense #%d: $", i);
        scanf("%f", &expense);
        expenses += expense;
    }

    float savings = income - expenses;

    printf("\nHere is your monthly financial summary:\n");
    printf("----------------------------------------\n");
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", expenses);
    printf("Savings: $%.2f\n", savings);

    if (savings >= 0) {
        printf("Congratulations! You have leftover savings this month.\n");
    } else {
        printf("Uh oh, looks like you overspent this month. Time to cut back on expenses!\n");
    }

    return 0;
}