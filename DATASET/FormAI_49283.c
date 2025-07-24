//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>

int main() {
    float income, expenses, savings;
    char choice;

    printf("Welcome to Personal Finance Planner\n");

    do {
        printf("\nEnter monthly income: ");
        scanf("%f", &income);

        printf("Enter monthly expenses: ");
        scanf("%f", &expenses);

        savings = income - expenses;

        printf("\nMonthly savings: $%.2f\n", savings);

        if (savings < 0) {
            printf("You are spending more than you earn! Better start cutting down expenses.\n");
        } else if (savings >= 0 && savings <= 500) {
            printf("Your savings is below average. Try to increase it.\n");
        } else if (savings > 500 && savings <= 1000) {
            printf("Your savings is average. Keep it up!\n");
        } else if (savings > 1000) {
            printf("Your savings is above average. Excellent job!\n");
        }

        printf("\nDo you want to continue? (y/n)");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using Personal Finance Planner.\n");

    return 0;
}