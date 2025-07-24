//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {

    /* Define variables for financial data */
    float income, expenses, savings;
    int num_months;

    /* Get user input for financial data */
    printf("Enter your income: ");
    scanf("%f", &income);

    printf("Enter your expenses: ");
    scanf("%f", &expenses);

    printf("Enter the number of months to plan for: ");
    scanf("%d", &num_months);

    /* Calculate monthly savings and total savings */
    savings = (income - expenses) * num_months;

    /* Print financial plan */
    printf("\n***** Personal Finance Planner *****\n\n");
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", expenses);
    printf("Savings per Month: $%.2f\n", (income - expenses));
    printf("Total Savings in %d Months: $%.2f\n", num_months, savings);

    /* Determine if savings goals are met */
    if (savings >= 10000) {
        printf("Congratulations! You have met your savings goal of $10,000 in %d months.", num_months);
    } else if (savings > 0) {
        printf("Keep saving! You are on track to reach your savings goal of $10,000 in %d months.", num_months);
    } else {
        printf("Oops! It looks like you need to adjust your budget in order to reach your savings goal of $10,000 in %d months.", num_months);
    }

    return 0;
}