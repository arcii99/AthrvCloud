//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    float monthly_income, rent, food, utilities, transportation, taxes, savings, total_expenses;
    int num_days;

    printf("Welcome to the Personal Finance Planner! Let's get started.\n\n");

    printf("Enter your monthly income: $");
    scanf("%f", &monthly_income);

    printf("\nEnter your monthly rent amount: $");
    scanf("%f", &rent);

    printf("\nEnter your monthly food expenses: $");
    scanf("%f", &food);

    printf("\nEnter your monthly utilities expenses: $");
    scanf("%f", &utilities);

    printf("\nEnter your monthly transportation expenses: $");
    scanf("%f", &transportation);

    printf("\nEnter your monthly taxes: $");
    scanf("%f", &taxes);

    printf("\nEnter the number of days in the month: ");
    scanf("%d", &num_days);

    total_expenses = rent + food + utilities + transportation + taxes;

    printf("\nYour total monthly expenses are: $%.2f", total_expenses);

    if(total_expenses > monthly_income) {
        savings = 0;
        printf("\n\nSorry, you are running a deficit. You cannot save money this month.");
    } else {
        savings = monthly_income - total_expenses;
        printf("\n\nYour monthly savings: $%.2f", savings);
    }

    printf("\n\nYour daily expenses are: $%.2f", total_expenses/num_days);
    printf("\n\n");

    return 0;
}