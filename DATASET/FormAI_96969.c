//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>

// Function to calculate savings based on income, expenses, and monthly savings goal
float calculateSavings(float income, float expenses, float monthlySavingsGoal) {
    float savings = income - expenses - monthlySavingsGoal;
    return savings;
}

// Function to print out a budget summary
void printBudgetSummary(float income, float expenses, float savings) {
    printf("\n**** Budget Summary ****\n");
    printf("Total Income: $%.2f\n", income);
    printf("Total Expenses: $%.2f\n", expenses);
    printf("Total Monthly Savings: $%.2f\n", savings);
    if (savings < 0) {
        printf("WARNING: Negative Savings!\n");
    }
    printf("*************************\n");
}

// Function to get user input for income, expenses, and monthly savings goal
void getUserInput(float *income, float *expenses, float *monthlySavingsGoal) {
    printf("Enter your monthly income: ");
    scanf("%f", income);
    printf("Enter your monthly expenses: ");
    scanf("%f", expenses);
    printf("Enter your monthly savings goal: ");
    scanf("%f", monthlySavingsGoal);
    printf("\n");
}

int main() {
    // Declare variables
    float income, expenses, monthlySavingsGoal, savings;

    // Get user input
    getUserInput(&income, &expenses, &monthlySavingsGoal);

    // Calculate savings
    savings = calculateSavings(income, expenses, monthlySavingsGoal);

    // Print budget summary
    printBudgetSummary(income, expenses, savings);

    return 0;
}