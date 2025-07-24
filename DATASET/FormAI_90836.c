//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

/* A peaceful personal finance planner program */

int main () {
    int income, rent, utility, groceries, savings, vacation;
    
    // Get user's income
    printf("Enter your monthly income: $");
    scanf("%d", &income);
    
    // Get user's fixed expenses
    printf("Enter your monthly rent/mortgage payment: $");
    scanf("%d", &rent);
    printf("Enter your monthly utility bills: $");
    scanf("%d", &utility);
    printf("Enter your monthly grocery expenses: $");
    scanf("%d", &groceries);
    
    // Calculate user's savings and discretionary spending
    savings = (income - rent - utility - groceries) * 0.2; // 20% of remaining income
    vacation = (income - rent - utility - groceries - savings); // The rest goes to vacation savings
    
    // Print out the plan
    printf("\n\nPersonal Finance Planner\n");
    printf("----------------------------\n");
    printf("Your Monthly Income: $%d\n", income);
    printf("Your Fixed Expense:\n");
    printf("	- Rent/Mortgage Payment: $%d\n", rent);
    printf("	- Utility Bills: $%d\n", utility);
    printf("	- Grocery Expenses: $%d\n", groceries);
    printf("	---------------------------\n");
    printf("Your Total Fixed Expense: $%d\n", rent + utility + groceries);
    printf("\n");
    printf("Your Savings Plan:\n");
    printf("	- Save 20%% of remaining income: $%d\n", savings);
    printf("\n");
    printf("Your Discretionary Spending Plan:\n");
    printf("	- Vacation Savings: $%d\n", vacation);
    
    return 0;
}