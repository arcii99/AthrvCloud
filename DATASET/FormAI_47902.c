//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Structure for the Personal Finance Plan
struct PersonalFinancePlan {
    float income;
    float expenses;
    float savings;
};

int main() {
    // Creating object of the PersonalFinancePlan structure
    struct PersonalFinancePlan pfp;

    // Accepting input from the user
    printf("Enter your monthly income: ");
    scanf("%f", &pfp.income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &pfp.expenses);

    // Calculating the savings
    pfp.savings = pfp.income - pfp.expenses;

    // Displaying the result
    printf("\nYour Personal Finance Plan: \n");
    printf("------------------------------\n");
    printf("Monthly Income: $%.2f\n", pfp.income);
    printf("Monthly Expenses: $%.2f\n", pfp.expenses);
    printf("Monthly Savings: $%.2f\n", pfp.savings);

    // Creating a budget analysis
    if(pfp.savings > 0) {
        printf("\nYour budget seems to be in control. You are saving $%.2f each month.", pfp.savings);
    }
    else if(pfp.savings == 0) {
        printf("\nYour budget seems to be breaking even. You are not saving anything, but you are not overspending either.");
    }
    else {
        printf("\nYour budget seems to be running a deficit. You need to cut down your expenses.");
    }

    return 0;
}