//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>

int main()
{
    // Declare variables to store user-input values
    float income;
    float expenses;
    float savings;

    // Get user input
    printf("Enter your monthly income: $");
    scanf("%f", &income);
    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);

    // Calculate savings
    savings = income - expenses;

    // Display results
    printf("\n\n========== Monthly Financial Plan ==========\n\n");
    printf("Income:\t\t $%.2f\n", income);
    printf("Expenses:\t $%.2f\n", expenses);
    printf("Savings:\t $%.2f\n", savings);

    // Provide financial advice to the user
    if (savings > 0)
    {
        printf("\nCongratulations! You are on track to building your savings!\n");
        printf("You should consider investing your extra income in a high-yield savings account or\n");
        printf("putting it towards your long-term financial goals, such as retirement or buying a house!\n");
    }
    else if (savings < 0)
    {
        printf("\nOops! You are spending more than you are earning.\n");
        printf("You should adjust your expenses and start living within your means.\n");
        printf("Consider cutting down on unnecessary expenses or finding ways to increase your income.\n");
    }
    else
    {
        printf("\nYou are breaking even. This means you are living within your means.\n");
        printf("You should continue to keep track of your expenses and income to maintain this balance.\n");
    }

    return 0;
}