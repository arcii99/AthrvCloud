//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>

int main() {
    float income, expenses, savings;
    
    // Get user inputs for income and expenses
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);
    
    // Calculate monthly savings
    savings = income - expenses;
    
    // Print monthly budget details
    printf("\n==== MONTHLY BUDGET ====\n");
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", expenses);
    printf("Savings: $%.2f\n", savings);
    printf("\n");
    
    // Calculate savings over 1 year with compound interest
    float interest_rate = 0.05;
    float savings_year = savings * 12;
    for(int i=0; i<12; i++) {
        savings_year = savings_year + (savings_year * interest_rate);
    }
    
    // Print savings over 1 year
    printf("Savings over 1 year with 5%% compound interest: $%.2f\n", savings_year);
    printf("\n");
    
    // Calculate and print percentage breakdown of expenses
    printf("Expense Breakdown:\n");
    printf("Housing: %.2f%%\n", (expenses * 0.3)/income * 100);
    printf("Transportation: %.2f%%\n", (expenses * 0.15)/income * 100);
    printf("Food: %.2f%%\n", (expenses * 0.1)/income * 100);
    printf("Entertainment: %.2f%%\n", (expenses * 0.05)/income * 100);
    printf("Other: %.2f%%\n", (expenses * 0.4)/income * 100);
    
    return 0;
}