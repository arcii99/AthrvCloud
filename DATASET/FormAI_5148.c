//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>

// Define struct to handle financial data
struct FinancialData {
    float income;
    float expenses;
    float savings;
};

// Function to calculate savings
float calculateSavings(float income, float expenses) {
    return income - expenses;
}

// Main function
int main() {
    // Initialize variables
    struct FinancialData data;
    float income, expenses, savings;

    // Prompt user for income and expenses
    printf("Enter your income: $");
    scanf("%f", &income);
    printf("Enter your expenses: $");
    scanf("%f", &expenses);

    // Update struct with financial data
    data.income = income;
    data.expenses = expenses;
    data.savings = calculateSavings(income, expenses);

    // Output financial data to user
    printf("\nYour financial data:\n");
    printf("Income: $%.2f\n", data.income);
    printf("Expenses: $%.2f\n", data.expenses);
    printf("Savings: $%.2f\n", data.savings);

    // Check if savings is positive or negative
    if (data.savings > 0) {
        printf("\nYou are saving money each month. Good job!\n");
    } else if (data.savings < 0) {
        printf("\nYou are spending more money than you make each month. You should consider making some changes.\n");
    } else {
        printf("\nYou are not saving or spending any money. Consider making some changes to improve your financial situation.\n");
    }

    return 0;
}