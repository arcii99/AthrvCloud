//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define some global variables
double monthly_income, rent, utilities, groceries, transportation, entertainment, other_expenses, savings;

void run_personal_finance_planner() {
    // Welcome message
    printf("Welcome to the Personal Finance Planner!\n\n");
    
    // Get user input for monthly income
    printf("Please enter your monthly income: ");
    scanf("%lf", &monthly_income);
    
    // Get user input for each expense category
    printf("\nEnter your monthly expenses:\n");
    printf("  Rent/mortgage: ");
    scanf("%lf", &rent);
    printf("  Utilities: ");
    scanf("%lf", &utilities);
    printf("  Groceries: ");
    scanf("%lf", &groceries);
    printf("  Transportation: ");
    scanf("%lf", &transportation);
    printf("  Entertainment: ");
    scanf("%lf", &entertainment);
    printf("  Other expenses: ");
    scanf("%lf", &other_expenses);
    
    // Calculate savings
    savings = monthly_income - rent - utilities - groceries - transportation - entertainment - other_expenses;
    
    // Print out the results
    printf("\n\nYour monthly finances:\n");
    printf("  Income: $%.2lf\n", monthly_income);
    printf("  Rent/mortgage: $%.2lf\n", rent);
    printf("  Utilities: $%.2lf\n", utilities);
    printf("  Groceries: $%.2lf\n", groceries);
    printf("  Transportation: $%.2lf\n", transportation);
    printf("  Entertainment: $%.2lf\n", entertainment);
    printf("  Other expenses: $%.2lf\n", other_expenses);
    printf("  Savings: $%.2lf\n", savings);
}

int main() {
    run_personal_finance_planner();
    return 0;
}