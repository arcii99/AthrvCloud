//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>

int main() {
    float income, expenses, savings;

    // Get user input
    printf("Enter your monthly income: $ ");
    scanf("%f", &income);
    printf("Enter your monthly expenses: $ ");
    scanf("%f", &expenses);

    // Calculate savings
    savings = income - expenses;

    // Display results
    printf("\n\n------------------\n");
    printf("| Monthly Summary |\n");
    printf("------------------\n");
    printf("Monthly Income: $ %.2f\n", income);
    printf("Monthly Expenses: $ %.2f\n", expenses);
    printf("Monthly Savings: $ %.2f\n", savings);

    // Determine if user is saving enough
    if (savings >= income * 0.20) {
        printf("\nGreat job! You are saving at least 20%% of your income.\n");
    } else if (savings >= 0) {
        printf("\nYou are saving less than 20%% of your income. Consider cutting expenses or increasing income.\n");
    } else {
        printf("\nOops! You are spending more than you earn. Consider cutting expenses or increasing income.\n");
    }

    return 0;
}