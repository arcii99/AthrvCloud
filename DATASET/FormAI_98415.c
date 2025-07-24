//FormAI DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {

    char expense_type;
    float amount;
    float total_expense = 0;

    printf("Welcome to the Expense Tracker program.\n");

    while (1) {
        printf("\nEnter the type of expense (E for Expense, I for Income, Q to quit): ");
        scanf(" %c", &expense_type);

        switch (expense_type) {
            case 'E':
                printf("\nEnter the amount of expense: ");
                scanf("%f", &amount);
                total_expense -= amount;
                printf("Expense of $%.2f recorded.\n", amount);
                printf("Total expense so far: $%.2f\n", total_expense);
                break;
            case 'I':
                printf("\nEnter the amount of income: ");
                scanf("%f", &amount);
                total_expense += amount;
                printf("Income of $%.2f recorded.\n", amount);
                printf("Total income so far: $%.2f\n", total_expense);
                break;
            case 'Q':
                printf("\nFinal total expense: $%.2f\n", total_expense);
                printf("Thank you for using the Expense Tracker program.");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.");
                break;
        }
    }

    return 0;
}