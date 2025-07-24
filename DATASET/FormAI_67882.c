//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>

int main() {
    // Variables for user input
    double monthlyIncome, savingsGoal, monthlyExpenses, savingsRate;

    // Variables for calculations
    double remainingIncome, savingsPerMonth, monthsToGoal;

    // Prompt user for input
    printf("Welcome to the Personal Finance Planner!\n\n");
    printf("Please enter your monthly income: $");
    scanf("%lf", &monthlyIncome);
    printf("Please enter your monthly expenses: $");
    scanf("%lf", &monthlyExpenses);
    printf("What percentage of your income would you like to save? (Enter as a decimal): ");
    scanf("%lf", &savingsRate);
    printf("What is your desired savings goal? $");
    scanf("%lf", &savingsGoal);

    // Calculate savings per month and months to goal
    remainingIncome = monthlyIncome - monthlyExpenses;
    savingsPerMonth = remainingIncome * savingsRate;
    monthsToGoal = savingsGoal / savingsPerMonth;

    // Display results to user
    printf("\nBased on your input, here is what we recommend:\n\n");
    printf("You should save $%.2lf per month.\n", savingsPerMonth);
    printf("It will take you %.0lf months to save $%.2lf.\n", monthsToGoal, savingsGoal);

    return 0;
}