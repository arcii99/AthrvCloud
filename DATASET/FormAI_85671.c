//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>

// Define a struct to hold financial information
typedef struct {
    float income; // Monthly income in dollars
    float expenses; // Monthly expenses in dollars
    float savingsRate; // Percentage of income saved
    float savings; // Amount of savings in dollars
    float debt; // Amount of debt in dollars
    float netWorth; // Total net worth in dollars
} PersonalFinance;

int main() {
    PersonalFinance myFinances; // Initialize a PersonalFinance struct
    
    // Get financial information from the user
    printf("Enter your monthly income: $");
    scanf("%f", &myFinances.income);
    printf("Enter your monthly expenses: $");
    scanf("%f", &myFinances.expenses);
    printf("Enter your savings rate (as a decimal between 0 and 1): ");
    scanf("%f", &myFinances.savingsRate);
    printf("Enter your amount of debt: $");
    scanf("%f", &myFinances.debt);
    
    // Calculate savings and net worth
    myFinances.savings = myFinances.income * myFinances.savingsRate;
    myFinances.netWorth = myFinances.savings - myFinances.debt;
    
    // Print financial information
    printf("\nFINANCIAL STATEMENT\n");
    printf("Monthly Income: $%.2f\n", myFinances.income);
    printf("Monthly Expenses: $%.2f\n", myFinances.expenses);
    printf("Savings Rate: %.2f%%\n", myFinances.savingsRate * 100);
    printf("Savings: $%.2f\n", myFinances.savings);
    printf("Debt: $%.2f\n", myFinances.debt);
    printf("Net Worth: $%.2f\n", myFinances.netWorth);
    
    return 0;
}