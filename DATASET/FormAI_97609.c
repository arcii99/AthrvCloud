//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: genious
#include <stdio.h>

// Define the struct for the personal finance planner
typedef struct {
    float income;
    float expenses;
    float savings;
} PersonalFinancePlanner;

int main() {
    // Create a new instance of the PersonalFinancePlanner
    PersonalFinancePlanner pfp;

    printf("Welcome to the Personal Finance Planner\n");

    // Ask for the user's income and store it in the pfp instance
    printf("Please enter your income: ");
    scanf("%f", &pfp.income);

    // Ask for the user's expenses and store it in the pfp instance
    printf("Please enter your expenses: ");
    scanf("%f", &pfp.expenses);

    // Calculate the savings by subtracting expenses from income
    pfp.savings = pfp.income - pfp.expenses;

    // Output the user's income, expenses, and savings
    printf("\nResults:\n");
    printf("Income: %.2f\n", pfp.income);
    printf("Expenses: %.2f\n", pfp.expenses);
    printf("Savings: %.2f\n", pfp.savings);

    // Check if the user is saving more than 20% of their income
    if (pfp.savings >= (pfp.income * 0.2)) {
        printf("Congratulations! You are saving more than 20%% of your income! Keep up the good work.\n");
    } else {
        printf("You are not saving more than 20%% of your income. Consider reducing your expenses or finding ways to increase your income.\n");
    }

    return 0;
}