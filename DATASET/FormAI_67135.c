//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#define MAX_EXPENSES 100   // set maximum expenses to 100

int main()
{
    float expenses[MAX_EXPENSES];
    int num_expenses = 0;   // set the initial number of expenses to 0
    float total_expenses = 0;
    char choice = ' ';

    printf("Welcome to the Expense Tracker!\n\n");

    do {
        printf("Enter expense amount: ");
        scanf("%f", &expenses[num_expenses]);
        total_expenses += expenses[num_expenses];   // add expense to total expenses
        num_expenses++;   // increment the number of expenses

        printf("Do you want to enter another expense? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nYou entered %d expenses totalling $%.2f.\n", num_expenses, total_expenses);

    // display each expense on a separate line
    printf("\nExpense breakdown:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("$%.2f\n", expenses[i]);
    }

    return 0;
}