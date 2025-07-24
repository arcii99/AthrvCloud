//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: genious
#include <stdio.h>

void main(){
    // Define variables for monthly income, expenses, and savings
    float monthly_income, monthly_expenses, monthly_savings;

    // Get user input for monthly income
    printf("Enter your monthly income: ");
    scanf("%f", &monthly_income);

    // Get user inputs for monthly expenses
    float rent, utilities, groceries, transportation, entertainment;
    printf("Enter your monthly rent: ");
    scanf("%f", &rent);
    printf("Enter your monthly utilities: ");
    scanf("%f", &utilities);
    printf("Enter your monthly groceries: ");
    scanf("%f", &groceries);
    printf("Enter your monthly transportation: ");
    scanf("%f", &transportation);
    printf("Enter your monthly entertainment: ");
    scanf("%f", &entertainment);

    // Calculate total monthly expenses
    monthly_expenses = rent + utilities + groceries + transportation + entertainment;

    // Calculate monthly savings
    monthly_savings = monthly_income - monthly_expenses;

    // Print monthly budget summary
    printf("\n-----MONTHLY BUDGET SUMMARY-----\n");
    printf("Monthly Income: $%.2f\n", monthly_income);
    printf("Monthly Expenses: $%.2f\n", monthly_expenses);
    printf("Monthly Savings: $%.2f\n", monthly_savings);

    // Determine if user is saving enough based on recommended 20% savings goal
    float twenty_percent_savings = 0.20 * monthly_income;
    if (monthly_savings >= twenty_percent_savings) {
        printf("You are saving enough! Keep up the good work.");
    } else {
        printf("You should aim to save at least $%.2f each month.", twenty_percent_savings);
    }
}