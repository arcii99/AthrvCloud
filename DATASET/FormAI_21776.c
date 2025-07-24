//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>

int main() {
    float monthly_income, total_expenses;
    int num_months;
    float budget, average_expenses;

    printf("Enter your monthly income: $");
    scanf("%f", &monthly_income);

    printf("Enter the number of months to budget: ");
    scanf("%d", &num_months);

    // Calculate total expenses over specified number of months
    for(int i = 1; i <= num_months; i++) {
        float expenses;
        printf("Enter total expenses for month %d: $", i);
        scanf("%f", &expenses);

        total_expenses += expenses;
    }

    // Calculate budget and average monthly expenses
    budget = monthly_income * num_months;
    average_expenses = total_expenses / num_months;

    printf("Total income for %d months: $%.2f\n", num_months, budget);
    printf("Total expenses for %d months: $%.2f\n", num_months, total_expenses);
    printf("Average monthly expenses: $%.2f\n", average_expenses);

    // Check if budget was met or not
    if(total_expenses <= budget) {
        printf("Congratulations! You stayed within your budget.\n");
    } else {
        float over_budget = total_expenses - budget;
        printf("Sorry, you went over your budget by $%.2f.\n", over_budget);
    }

    return 0;
}