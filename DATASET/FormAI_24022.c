//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>

int main() {
    float income, housing, utilities, transportation, groceries, savings;
    
    printf("Welcome to the Personal Finance Planner \n");
    printf("Please enter your monthly income: $");
    scanf("%f", &income);
    
    printf("\n---Monthly Expenses---\n");
    
    printf("Housing: $");
    scanf("%f", &housing);
    
    printf("Utilities: $");
    scanf("%f", &utilities);
    
    printf("Transportation: $");
    scanf("%f", &transportation);
    
    printf("Groceries: $");
    scanf("%f", &groceries);
    
    printf("\n---Savings Goals---\n");
    
    printf("Emergency Fund: $");
    scanf("%f", &savings);
    
    float total_expenses = housing + utilities + transportation + groceries;
    float remaining_income = income - total_expenses - savings;
    
    printf("\n---Monthly Summary---\n");
    printf("Total Expenses: $%.2f \n", total_expenses);
    printf("Remaining Income: $%.2f \n", remaining_income);
    printf("Savings Goal: $%.2f \n", savings);
    
    return 0;
}