//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>

int main()
{
    float monthly_income, monthly_expenses, savings_goal;
    int months_to_reach_goal;

    printf("Monthly Income: ");
    scanf("%f", &monthly_income);

    printf("Monthly Expenses: ");
    scanf("%f", &monthly_expenses);

    printf("Savings Goal: ");
    scanf("%f", &savings_goal);

    printf("Number of Months to Reach Goal: ");
    scanf("%d", &months_to_reach_goal);

    float monthly_savings = (monthly_income - monthly_expenses);
    float total_savings = monthly_savings * months_to_reach_goal;

    printf("\n---------------------------------------------\n");
    printf("                Financial Plan                \n");
    printf("---------------------------------------------\n");
    printf("Monthly Income: $%.2f\n", monthly_income);
    printf("Monthly Expenses: $%.2f\n", monthly_expenses);
    printf("Monthly Savings: $%.2f\n", monthly_savings);
    printf("Savings Goal: $%.2f\n", savings_goal);
    printf("Months to Reach Goal: %d\n", months_to_reach_goal);
    printf("Total Savings Needed: $%.2f\n", savings_goal * months_to_reach_goal);
    printf("Total Savings: $%.2f\n", total_savings);
    printf("\n---------------------------------------------\n");

    if (total_savings >= (savings_goal * months_to_reach_goal))
    {
        printf("\nCongratulations! You have met your savings goal!\n");
    }
    else
    {
        printf("\nYou need to save more to meet your goal. Keep going!\n");
    }

    return 0;
}