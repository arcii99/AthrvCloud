//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
    float income, expense;
    float savings, balance;
    int choice;

    printf("Personal Finance Planner\n");
    printf("========================\n\n");
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly expense: ");
    scanf("%f", &expense);

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Calculate your monthly savings\n");
        printf("2. Calculate your balance at the end of the year\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                savings = income - expense;
                printf("\nYour monthly savings: $%.2f\n", savings);
                break;
            case 2:
                balance = (income - expense) * 12;
                printf("\nYour balance at the end of the year: $%.2f\n", balance);
                break;
            case 3:
                printf("\nThank you for using Personal Finance Planner!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose again.\n");
                break;
        }

    } while(choice != 3);

    return 0;
}