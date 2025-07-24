//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
    float monthly_income = 0.0, monthly_expenses = 0.0, savings_goal = 0.0;
    int num_months = 0;

    printf("Welcome to your Personal Finance Planner!\n");

    printf("Please input your monthly income: $");
    scanf("%f", &monthly_income);

    printf("Please input your monthly expenses: $");
    scanf("%f", &monthly_expenses);

    printf("Please input your desired savings goal: $");
    scanf("%f", &savings_goal);

    printf("Please input the number of months you plan to save: ");
    scanf("%d", &num_months);

    float savings_per_month = (monthly_income - monthly_expenses) - savings_goal / num_months;
    printf("You need to save $%.2f each month to reach your savings goal in %d months!\n", savings_per_month, num_months);

    return 0;
}