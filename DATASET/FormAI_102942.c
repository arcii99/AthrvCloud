//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
// C Personal Finance Planner Example Program
// By [Your Name]

#include<stdio.h>

int main()
{
    double monthly_income, monthly_expenses, savings_goal;
    int num_of_months = 12;

    // Taking user input for monthly income, monthly expenses, and savings goal
    printf("Enter monthly income: ");
    scanf("%lf", &monthly_income);

    printf("Enter monthly expenses: ");
    scanf("%lf", &monthly_expenses);

    printf("Enter savings goal: ");
    scanf("%lf", &savings_goal);

    // Calculating annual income, annual expenses, and annual savings
    double annual_income = monthly_income * num_of_months;
    double annual_expenses = monthly_expenses * num_of_months;
    double annual_savings = (annual_income - annual_expenses);

    // Checking if savings goal is achievable or not
    if(annual_savings < savings_goal)
    {
        printf("Savings goal is not achievable. Try reducing your expenses.\n");
    }
    else
    {
        int months_needed = (int)(savings_goal / (annual_savings / num_of_months));

        printf("You need to save for %d months to achieve your savings goal.\n", months_needed);
    }

    return 0;
}