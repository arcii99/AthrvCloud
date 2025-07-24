//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>

int main() {
    printf("Welcome to the Personal Finance Planner\n");
    printf("Please enter your income for the month: ");
    double income;
    scanf("%lf", &income);

    double expenses = 0;
    int num_expenses = 0;
    char answer;

    while (answer != 'n') {
        printf("Enter an expense amount: ");
        double expense;
        scanf("%lf", &expense);
        expenses += expense;
        num_expenses++;

        printf("Do you want to enter another expense? (y/n): ");
        scanf(" %c", &answer);

        if (expenses >= income) {
            printf("WARNING: Your expenses have surpassed your income. Be careful!\n");
        }
    }

    double remaining = income - expenses;
    printf("Here is your monthly spending summary:\n");
    printf("Income      : $%.2f\n", income);
    printf("Expenses    : $%.2f\n", expenses);
    printf("Remaining   : $%.2f\n", remaining);
    printf("Num expenses: %d\n", num_expenses);

    if (remaining <= 0) {
        printf("WARNING: You have no remaining funds for the month. Consider adjusting your expenses.\n");
    }

    return 0;
}