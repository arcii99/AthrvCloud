//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {

    float monthly_income, monthly_expenses, savings_goal, savings_percentage;
    float monthly_savings, yearly_savings, years_to_goal;

    printf("Personal Finance Planner\n\n");

    printf("Enter your monthly income: ");
    scanf("%f", &monthly_income);

    printf("Enter your monthly expenses: ");
    scanf("%f", &monthly_expenses);

    printf("Enter your savings goal: ");
    scanf("%f", &savings_goal);

    printf("Enter your desired savings percentage: ");
    scanf("%f", &savings_percentage);

    // Calculate monthly and yearly savings
    monthly_savings = (monthly_income * savings_percentage) / 100;
    yearly_savings = monthly_savings * 12;

    // Calculate years to reach savings goal
    years_to_goal = savings_goal / yearly_savings;

    printf("\nMonthly Savings: $%.2f\n", monthly_savings);
    printf("Yearly Savings: $%.2f\n", yearly_savings);
    printf("Time to reach savings goal: %.1f years\n", years_to_goal);

    // Conditional statement to check if years is a whole number or decimal
    if (years_to_goal == (int)years_to_goal) {
        printf("You will reach your savings goal in %d years.\n", (int)years_to_goal);
    } else {
        printf("You will reach your savings goal in %.1f years.\n", years_to_goal);
    }

    // Calculate and display budget after savings
    float budget = monthly_income - monthly_expenses - monthly_savings;
    printf("Budget after savings: $%.2f\n", budget);

    return 0;
}