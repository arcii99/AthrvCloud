//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Personal Finance Planner!\n\n");

    float monthly_income, monthly_expenses, savings_goal;
    int months_to_goal;

    printf("Please enter your monthly income: \n");
    scanf("%f", &monthly_income);

    printf("Please enter your monthly expenses: \n");
    scanf("%f", &monthly_expenses);

    printf("Please enter your savings goal: \n");
    scanf("%f", &savings_goal);

    printf("Please enter the number of months you want to achieve your savings goal in: \n");
    scanf("%d", &months_to_goal);

    float savings_per_month = monthly_income - monthly_expenses;
    printf("Your savings per month is: %.2f\n", savings_per_month);

    float total_savings = savings_per_month * months_to_goal;
    printf("Your total savings in %d months will be: %.2f\n", months_to_goal, total_savings);

    if(total_savings >= savings_goal)
    {
        printf("Congratulations! You will be able to meet your savings goal in %d months.\n", months_to_goal);
    }
    else
    {
        int additional_months = (int) ((savings_goal - total_savings) / savings_per_month) + 1;
        printf("You will need an additional %d months to meet your savings goal.\n", additional_months);
    }

    return 0;
}