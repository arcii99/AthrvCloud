//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: artistic
#include <stdio.h>

int main() {
    double total_income, total_expenses, net_savings;
    double income_sources, expense_categories, savings_goals;

    printf("Welcome to your Personal Finance Planner!\n\n");
    printf("Please enter your total income for this month: $");
    scanf("%lf", &total_income);

    printf("\nGreat! Now, let's talk about your income sources.\n");
    printf("Enter the number of sources of income you have this month: ");
    scanf("%lf", &income_sources);

    double average_income_per_source = total_income / income_sources;
    printf("\nYour average income per source is: $%.2lf\n", average_income_per_source);

    printf("\nNow, let's move on to your expenses.\n");
    printf("Enter the number of expense categories you have this month: ");
    scanf("%lf", &expense_categories);

    double average_expense_per_category = total_expenses / expense_categories;
    printf("\nYour average expense per category is: $%.2lf\n", average_expense_per_category);

    printf("\nHow much do you plan to save this month? $");
    scanf("%lf", &savings_goals);

    net_savings = total_income - total_expenses - savings_goals;

    if (net_savings > 0) {
        printf("\nCongratulations! You have a positive net savings of $%.2lf this month.\n", net_savings);
    } else if (net_savings < 0) {
        printf("\nUh-oh! You have a negative net savings of $%.2lf this month. Consider cutting back on expenses.\n", net_savings);
    } else {
        printf("\nYou have neither saved nor overspent this month. Keep up the good work!\n");
    }

    return 0;
}