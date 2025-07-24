//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>

int main() {
    // declare variables
    float monthly_income, monthly_expenses, savings_goal;
    int num_months;

    // get user input
    printf("Enter your monthly income: ");
    scanf("%f", &monthly_income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &monthly_expenses);
    printf("Enter your savings goal: ");
    scanf("%f", &savings_goal);
    printf("Enter the number of months you want to save for: ");
    scanf("%d", &num_months);

    // calculate total expenses and total savings
    float total_expenses = monthly_expenses * num_months;
    float total_savings = savings_goal * num_months;

    // calculate amount left over after expenses and savings
    float monthly_available = monthly_income - monthly_expenses;
    float total_available = monthly_available * num_months;

    // calculate percentage of income spent on expenses
    float expense_percentage = (monthly_expenses / monthly_income) * 100;

    // display results to the user
    printf("\nTotal expenses for %d months: $%.2f\n", num_months, total_expenses);
    printf("Total savings for %d months: $%.2f\n", num_months, total_savings);
    printf("Total available income for %d months: $%.2f\n", num_months, total_available);
    printf("Percentage of income spent on expenses: %.2f%%\n", expense_percentage);

    return 0;
}