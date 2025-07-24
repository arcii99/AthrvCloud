//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>

int main() {
    // Declare variables
    double income, expenses, savings, debt;
    
    // Get user input
    printf("Enter your monthly income: ");
    scanf("%lf", &income);
    
    printf("Enter your monthly expenses: ");
    scanf("%lf", &expenses);
    
    printf("Enter your monthly savings: ");
    scanf("%lf", &savings);
    
    printf("Enter your monthly debt repayment: ");
    scanf("%lf", &debt);
    
    // Calculate total amount left after expenses, debt payments, and savings
    double total = income - expenses - savings - debt;
    
    // Print summary
    printf("\n\n");
    printf("Monthly Income: $%.2lf\n", income);
    printf("Monthly Expenses: $%.2lf\n", expenses);
    printf("Monthly Savings: $%.2lf\n", savings);
    printf("Monthly Debt Repayment: $%.2lf\n", debt);
    printf("Total Amount Left: $%.2lf\n", total);
    
    return 0;
}