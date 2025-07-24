//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char name[50];
    float amount;
    int month;
};

int main() {
    int choice, i = 0;
    float totalExpenses = 0;
    struct Expense expenses[100];

    while (1) {
        printf("Enter 1 to add expense, 2 to view expenses, 3 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter expense name: ");
            scanf("%s", expenses[i].name);

            printf("Enter amount: ");
            scanf("%f", &expenses[i].amount);

            printf("Enter month (1-12): ");
            scanf("%d", &expenses[i].month);

            totalExpenses += expenses[i].amount;
            i++;
        } else if (choice == 2) {
            printf("Expenses recorded:\n");
            printf("Name\tAmount\tMonth\n");
            for(int j=0; j<i; j++){
                printf("%s\t%.2f\t%d\n", expenses[j].name, expenses[j].amount, expenses[j].month);
            }
            printf("Total expenses: %.2f\n", totalExpenses);
        } else if (choice == 3) {
            exit(0);
        } else {
            printf("Invalid choice. Try again.\n");
        }

        printf("\n");
    }

    return 0;
}