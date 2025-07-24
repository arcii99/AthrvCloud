//FormAI DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>

int main()
{
    float expense, total_expense = 0;
    int choice;

    printf("Welcome to the Expense Tracker app!\n");

    do
    {
        printf("\nEnter the expense: $");
        scanf("%f", &expense);

        if (expense < 0)
        {
            printf("\nInvalid expense amount!");
            continue;
        }

        total_expense += expense;

        printf("\nDo you wish to add more expenses?\n");
        printf("\t1. Yes\n");
        printf("\t2. No\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("\nTotal expenses for the day: $%.2f\n", total_expense);

    printf("\nWow! You spent $%.2f today. That's impressive!\n", total_expense);
    printf("How about treating yourself to a nice cup of coffee tomorrow?\n");

    return 0;
}