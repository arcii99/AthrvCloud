//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>

int main() {
    float income, rent, groceries, utilities, transportation, other_expenses, total_expenses;
    float balance;

    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly rent or mortgage payment: ");
    scanf("%f", &rent);
    printf("Enter your monthly grocery expenses: ");
    scanf("%f", &groceries);
    printf("Enter your monthly utilities expenses: ");
    scanf("%f", &utilities);
    printf("Enter your monthly transportation expenses: ");
    scanf("%f", &transportation);
    printf("Enter any other monthly expenses: ");
    scanf("%f", &other_expenses);

    total_expenses = rent + groceries + utilities + transportation + other_expenses;
    balance = income - total_expenses;

    printf("\n");
    if(balance > 0) {
        printf("Congratulations! You have a surplus of $%.2f per month.\n", balance);
    } else if(balance == 0) {
        printf("You broke even. Keep it up!\n");
    } else {
        printf("Oh no! You are overdrawn by $%.2f per month. Time to cut back.\n", -balance);
    }

    printf("\n");
    printf("Expense summary:\n");
    printf("- Rent or mortgage: $%.2f\n", rent);
    printf("- Groceries: $%.2f\n", groceries);
    printf("- Utilities: $%.2f\n", utilities);
    printf("- Transportation: $%.2f\n", transportation);
    printf("- Other expenses: $%.2f\n", other_expenses);
    printf("------------------------\n");
    printf("Total expenses: $%.2f\n", total_expenses);

    return 0;
}