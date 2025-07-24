//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include <stdio.h>

int main() {
    float income, expenses, savings;
    char option;

    printf("Welcome to the Personal Finance Planner\n\n");
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);
    printf("Enter 'S' if you would like to set a savings goal, or any other key to continue: ");
    scanf(" %c", &option);

    if (option == 'S' || option == 's') {
        float savings_goal;
        printf("Enter your desired monthly savings goal: ");
        scanf("%f", &savings_goal);
        savings = income - expenses - savings_goal;
    } else {
        savings = income - expenses;
    }

    printf("\nHere is your monthly budget breakdown:\n");
    printf("Income: %.2f\n", income);
    printf("Expenses: %.2f\n", expenses);
    printf("Savings: %.2f\n", savings);

    if (savings < 0) {
        printf("\nWARNING: You are spending more than you are earning!\n");
    } else if (savings < (0.1 * income)) {
        printf("\nCAUTION: Your savings are less than 10%% of your income. Consider reducing your expenses.\n");
    } else if (savings < (0.2 * income)) {
        printf("\nGOOD JOB: Your savings are between 10%% and 20%% of your income. Keep it up!\n");
    } else {
        printf("\nAWESOME: Your savings are more than 20%% of your income. You are doing great!\n");
    }

    return 0;
}