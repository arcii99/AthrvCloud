//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {

    // User's financial information
    float monthly_income;
    float monthly_expenses;
    float savings_goal;

    // Calculated financial information
    float monthly_savings;
    float months_to_goal;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your monthly income: ");
    scanf("%f", &monthly_income);
    
    printf("Please enter your monthly expenses: ");
    scanf("%f", &monthly_expenses);

    printf("Please enter your savings goal: ");
    scanf("%f", &savings_goal);

    monthly_savings = monthly_income - monthly_expenses;

    if (monthly_savings <= 0) {
        printf("Uh oh, your expenses are higher than your income! You need to either increase your income or decrease your expenses.\n");
    } else {
        months_to_goal = savings_goal / monthly_savings;

        printf("With your current monthly savings of $%.2f, you will reach your savings goal of $%.2f in %.1f months.\n", monthly_savings, savings_goal, months_to_goal);
    }

    return 0;
}