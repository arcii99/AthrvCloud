//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>

int main() {
    // Declare variables for monthly budget
    float income, rent, utilities, food, transportation, other, total_expenses, savings;

    // Get user input for monthly income and expenses
    printf("Enter your monthly income: $");
    scanf("%f", &income);

    printf("Enter your monthly rent or mortgage payment: $");
    scanf("%f", &rent);

    printf("Enter your monthly utilities cost (e.g. electricity, water, gas): $");
    scanf("%f", &utilities);

    printf("Enter your monthly food expense: $");
    scanf("%f", &food);

    printf("Enter your monthly transportation cost (e.g. gas, public transit): $");
    scanf("%f", &transportation);

    printf("Enter any other monthly expenses (e.g. entertainment, subscriptions): $");
    scanf("%f", &other);

    // Calculate the total monthly expenses and savings
    total_expenses = rent + utilities + food + transportation + other;
    savings = income - total_expenses;

    // Output the monthly budget
    printf("\n\n*** Your Monthly Budget ***\n");
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", total_expenses);
    printf("Savings: $%.2f", savings);

    return 0;
}