//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>

int main() {
    float income, expenses, savings, taxes;
    int num_months;

    printf("Personal Finance Planner\n");
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);
    printf("Enter the number of months to plan for: ");
    scanf("%d", &num_months);
    printf("\n");

    for (int i=1; i<=num_months; i++) {
        printf("Month %d\n", i);

        taxes = income * 0.3;
        income = income - taxes;

        savings = income - expenses;

        printf("- Income: %.2f\n", income);
        printf("- Taxes: %.2f\n", taxes);
        printf("- Expenses: %.2f\n", expenses);
        printf("- Savings: %.2f\n\n", savings);

        income += savings;
    }

    return 0;
}