//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

float income, expenses, savings;

int main() {
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);

    savings = income - expenses;

    printf("Your savings for the month is: $%.2f\n", savings);

    if (savings > 0) {
        printf("Congratulations! You're saving money this month.\n");
    } else if (savings < 0) {
        printf("Uh oh, you're spending more than you're making!\n");
    } else {
        printf("Your income and expenses are balanced this month.\n");
    }

    printf("\n");

    printf("Your budget breakdown for the month:\n");
    printf("Income:\t\t$%.2f\n", income);
    printf("Expenses:\t$%.2f\n", expenses);
    printf("Savings:\t$%.2f\n", savings);

    printf("\n");

    printf("Here are some tips to help you save more:\n");
    printf("- Make a budget and stick to it.\n");
    printf("- Cut down on unnecessary expenses, such as eating out or buying clothes.\n");
    printf("- Use coupons or discount codes when shopping.\n");
    printf("- Consider a side hustle to increase your income.\n");

    return 0;
}