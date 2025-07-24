//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// defining a struct to hold the financial data
typedef struct {
    float income;
    float expenses;
    float savings;
} financeData;

int main() {
    financeData user; // declaring a variable of type financeData

    // prompting user for input
    printf("Enter your income: ");
    scanf("%f", &user.income);
    printf("Enter your expenses: ");
    scanf("%f", &user.expenses);

    // calculating and displaying savings
    user.savings = user.income - user.expenses;
    printf("\nYour monthly savings: $%.2f\n", user.savings);

    // prompting user for savings goal
    float savingsGoal;
    printf("\nEnter your savings goal: ");
    scanf("%f", &savingsGoal);

    // calculating and displaying time to reach savings goal
    int monthsToGoal = savingsGoal / user.savings;
    printf("\nAt your current savings rate, it will take you %d months to reach your savings goal of $%.2f\n", monthsToGoal, savingsGoal);

    // prompting user for investment amount
    float investment;
    printf("\nEnter how much money you want to invest: ");
    scanf("%f", &investment);

    // calculating and displaying investment growth
    float growth = 0.06; // assuming 6% annual growth
    float investmentGrowth = investment + (investment * growth);
    printf("\nIf you invest $%.2f with a 6%% annual growth rate, your investment will grow to $%.2f in one year\n", investment, investmentGrowth);

    return 0;
}