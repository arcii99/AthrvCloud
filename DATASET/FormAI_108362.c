//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include <stdio.h>

int main() {
    float salary, expenses, savings, total_expenses = 0, total_savings = 0;
    int num_months;

    printf("Welcome to the Personal Finance Planner!\n\n");

    printf("Please enter your monthly salary: $");
    scanf("%f", &salary);

    printf("Please enter the number of months you would like to plan: ");
    scanf("%d", &num_months);

    for (int i = 1; i <= num_months; i++) {
        printf("\nMonth %d:\n", i);

        printf("Enter your total monthly expenses: $");
        scanf("%f", &expenses);
        total_expenses += expenses;

        savings = salary - expenses;
        total_savings += savings;

        printf("Your total monthly savings: $%.2f\n\n", savings);
    }

    printf("Total expenses for the %d month period: $%.2f\n", num_months, total_expenses);
    printf("Total savings for the %d month period: $%.2f\n", num_months, total_savings);

    return 0;
}