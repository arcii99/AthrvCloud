//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>

int main() {
    // Declare variables
    float monthly_income, housing_cost, transportation_cost, food_cost, entertainment_cost, misc_cost;
    float total_expenses, total_savings;
    const float tax_rate = 0.25;

    // Get user input for monthly income and expenses
    printf("Enter your monthly income: $");
    scanf("%f", &monthly_income);

    printf("Enter your monthly housing cost: $");
    scanf("%f", &housing_cost);

    printf("Enter your monthly transportation cost: $");
    scanf("%f", &transportation_cost);

    printf("Enter your monthly food cost: $");
    scanf("%f", &food_cost);

    printf("Enter your monthly entertainment cost: $");
    scanf("%f", &entertainment_cost);

    printf("Enter your monthly miscellaneous cost: $");
    scanf("%f", &misc_cost);

    // Calculate total expenses and savings
    total_expenses = housing_cost + transportation_cost + food_cost + entertainment_cost + misc_cost;
    total_savings = monthly_income - total_expenses - (monthly_income * tax_rate);

    // Display results
    printf("\nHere is your monthly personal finance report:\n");
    printf("---------------------------------------------\n");
    printf("Monthly Income: $%.2f\n", monthly_income);
    printf("Monthly Expenses: $%.2f\n", total_expenses);
    printf("Tax Deduction: $%.2f\n", monthly_income * tax_rate);
    printf("Monthly Savings: $%.2f", total_savings);

    return 0;
}