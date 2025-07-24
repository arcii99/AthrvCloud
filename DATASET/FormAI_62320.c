//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
    float income, expense, savings, totalIncome=0, totalExpense=0, totalSavings=0;
    int choice;

    printf("Welcome to the Personal Finance Planner\n\n");

    do {
        printf("Menu:\n");
        printf("1. Add income\n");
        printf("2. Add expense\n");
        printf("3. View total income, expense, and savings\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter income: ");
                scanf("%f", &income);
                totalIncome += income;
                printf("Income added successfully!\n\n");
                break;
            case 2:
                printf("\nEnter expense: ");
                scanf("%f", &expense);
                totalExpense += expense;
                printf("Expense added successfully!\n\n");
                break;
            case 3:
                printf("\nTotal Income: $%.2f\n", totalIncome);
                printf("Total Expense: $%.2f\n", totalExpense);
                savings = totalIncome - totalExpense;
                printf("Total Savings: $%.2f\n\n", savings);
                break;
            case 4:
                printf("\nThank you for using the Personal Finance Planner!\n\n");
                break;
            default:
                printf("\nInvalid input. Please try again.\n\n");
                break;
        }
    } while(choice != 4);

    return 0;
}