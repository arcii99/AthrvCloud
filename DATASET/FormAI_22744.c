//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare Variables
    float monthly_income;
    float monthly_expenses;
    float planned_savings;
    float unexpected_expenses;
    float total_savings;
    
    // Get User Input
    printf("Enter your monthly income: $");
    scanf("%f", &monthly_income);
    printf("Enter your monthly expenses: $");
    scanf("%f", &monthly_expenses);
    printf("Enter your planned monthly savings: $");
    scanf("%f", &planned_savings);
    printf("Enter any unexpected expenses incurred this month: $");
    scanf("%f", &unexpected_expenses);
    
    // Calculate Total Savings
    total_savings = (monthly_income - monthly_expenses) + planned_savings - unexpected_expenses;

    // Output Results
    printf("\n------------------------------------\n");
    printf("Personal Finance Planner\n");
    printf("------------------------------------\n");
    printf("Monthly Income: $%.2f\n", monthly_income);
    printf("Monthly Expenses: $%.2f\n", monthly_expenses);
    printf("Planned Monthly Savings: $%.2f\n", planned_savings);
    printf("Unexpected Expenses: $%.2f\n", unexpected_expenses);
    printf("------------------------------------\n");
    if (total_savings < 0) {
        printf("You have a deficit of: $%.2f\n", -1 * total_savings);
    } else if (total_savings == 0) {
        printf("You have no savings this month.\n");
    } else {
        printf("Total Savings this month: $%.2f\n", total_savings);
    }
    printf("------------------------------------\n");

    return 0;
}