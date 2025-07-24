//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>

int main() {

    printf("Welcome to the Personal Finance Planner!\n");
    printf("I am your friendly, neighborhood finance bot.\n");
    printf("Enter your monthly income: ");

    float income;
    scanf("%f", &income);

    printf("\nEnter your monthly expenses: ");

    float expenses;
    scanf("%f", &expenses);

    printf("\nEnter your monthly savings goal: ");

    float savings;
    scanf("%f", &savings);

    if (savings > income) {
        printf("\nOops, it looks like your savings goal is higher than your income.");
        printf("\nWhy don't you start by reducing your expenses a bit?\n");
        printf("Let me help you with that.\n\n");

        float new_expenses = expenses - ((savings - income) / 2);
        printf("New Monthly Expenses: $%.2f\n", new_expenses);

        if (new_expenses < 0) {
            printf("\nUmm, scratch that. It looks like we have to get creative.\n");
            printf("Here's what we'll do: start a lemonade stand, walk dogs or sell your hair.\n");
        } else {
            printf("\nAwesome! Now you have an extra $%.2f in savings each month.\n", (income - new_expenses) - savings);
        }
    } else {
        printf("\nGreat! You're already on track to meeting your savings goal each month.\n");
        printf("You have an extra $%.2f to spare.\n", income - expenses - savings);
    }

    return 0;
}