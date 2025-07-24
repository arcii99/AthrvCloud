//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>

// Function to calculate the total amount of savings
float calculateSavings(float expenses, float income) {
    float savings = income - expenses;
    return savings;
}

// Function to display the spending breakdown
void displayBreakdown(float expenses) {
    printf("\nSpending Breakdown:");
    printf("\n------------------");
    printf("\nFixed Expenses: $%.2f", expenses * 0.5);
    printf("\nFlexible Expenses: $%.2f", expenses * 0.3);
    printf("\nSavings: $%.2f", expenses * 0.2);
}

// Main function to prompt user inputs and display results
int main() {
    printf("Welcome to Personal Finance Planner!\n");

    // Prompt user for inputs
    printf("\nPlease enter your total monthly income: $");
    float income;
    scanf("%f", &income);

    printf("\nPlease enter your total monthly expenses: $");
    float expenses;
    scanf("%f", &expenses);

    // Calculate savings and display results
    float savings = calculateSavings(expenses, income);
    printf("\nTotal Monthly Savings: $%.2f", savings);

    // Display spending breakdown
    displayBreakdown(expenses);

    // Exit program
    printf("\n\nThank you for using Personal Finance Planner!\n");
    return 0;
}