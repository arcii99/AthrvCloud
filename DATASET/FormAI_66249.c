//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float monthlyIncome, monthlyExpenses, monthlySavings, goal;
    int numMonths;

    printf("Enter your monthly income: ");
    scanf("%f", &monthlyIncome);

    printf("Enter your monthly expenses: ");
    scanf("%f", &monthlyExpenses);

    monthlySavings = monthlyIncome - monthlyExpenses;
    printf("Your monthly savings: $%.2f\n", monthlySavings);

    printf("What is your savings goal?\n");
    scanf("%f", &goal);

    numMonths = goal / monthlySavings;

    printf("You will reach your savings goal in %d months!\n", numMonths);

    return 0;
}