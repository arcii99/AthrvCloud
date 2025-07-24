//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int salary, expenses, investments, savings;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your monthly salary (in dollars): ");
    scanf("%d", &salary);

    printf("Please enter your monthly expenses (in dollars): ");
    scanf("%d", &expenses);

    printf("Please enter your monthly investments (in dollars): ");
    scanf("%d", &investments);

    savings = salary - expenses - investments;

    printf("\n\n");
    printf("Your monthly savings: %d\n", savings);

    int total_savings = 0;

    printf("Enter the total number of months for which you want to calculate savings: ");
    int months;
    scanf("%d", &months);

    for (int i = 1; i <= months; i++) {
        int savings_this_month = 0;

        printf("Enter your monthly salary for month %d (in dollars): ", i);
        scanf("%d", &salary);

        printf("Enter your monthly expenses for month %d (in dollars): ", i);
        scanf("%d", &expenses);

        printf("Enter your monthly investments for month %d (in dollars): ", i);
        scanf("%d", &investments);

        savings_this_month = salary - expenses - investments;
        total_savings += savings_this_month;
    }

    printf("\n\n");
    printf("Total savings for %d months: %d\n", months, total_savings);

    return 0;
}