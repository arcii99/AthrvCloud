//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>

int main()
{
    float monthly_income;
    float housing_expenses;
    float utilities_expenses;
    float transportation_expenses;
    float food_expenses;
    float other_expenses;
    float total_expenses;
    float savings;

    printf("Enter your monthly income: $");
    scanf("%f", &monthly_income);

    printf("Enter your monthly housing expenses: $");
    scanf("%f", &housing_expenses);

    printf("Enter your monthly utilities expenses: $");
    scanf("%f", &utilities_expenses);

    printf("Enter your monthly transportation expenses: $");
    scanf("%f", &transportation_expenses);

    printf("Enter your monthly food expenses: $");
    scanf("%f", &food_expenses);

    printf("Enter your other monthly expenses: $");
    scanf("%f", &other_expenses);

    total_expenses = housing_expenses + utilities_expenses + transportation_expenses + food_expenses + other_expenses;
    savings = monthly_income - total_expenses;

    printf("\n");
    printf("Monthly Income: $%.2f\n", monthly_income);
    printf("Monthly Housing Expenses: $%.2f\n", housing_expenses);
    printf("Monthly Utilities Expenses: $%.2f\n", utilities_expenses);
    printf("Monthly Transportation Expenses: $%.2f\n", transportation_expenses);
    printf("Monthly Food Expenses: $%.2f\n", food_expenses);
    printf("Other Monthly Expenses: $%.2f\n", other_expenses);
    printf("Total Monthly Expenses: $%.2f\n", total_expenses);
    printf("Total Monthly Savings: $%.2f\n", savings);

    return 0;
}