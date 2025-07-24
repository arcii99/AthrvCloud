//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char detail[50];
    double amount;
    char currency[4];
} Expense;

typedef struct {
    Expense expenses[100];
    int count;
} ExpensesList;

void addExpense(ExpensesList *list) {
    if (list->count < 100) {
        printf("Enter Date (yyyy-mm-dd): ");
        scanf("%s", list->expenses[list->count].date);
        getchar();

        printf("Enter Expense Detail: ");
        fgets(list->expenses[list->count].detail, 50, stdin);
        list->expenses[list->count].detail[strcspn(list->expenses[list->count].detail, "\n")] = 0;

        printf("Enter Amount: ");
        scanf("%lf", &list->expenses[list->count].amount);

        printf("Enter Currency: ");
        scanf("%s", list->expenses[list->count].currency);

        printf("Expense Added!\n");
        list->count++;
    } else {
        printf("Could not add expense. Maximum number of expenses reached.\n");
    }
}

void displayExpenses(ExpensesList *list) {
    printf("\nExpenses List:\n");
    for (int i=0; i<list->count; i++) {
        printf("-----------------------------------------\n");
        printf("Expense #%d\n", i+1);
        printf("Date: %s\n", list->expenses[i].date);
        printf("Detail: %s\n", list->expenses[i].detail);
        printf("Amount: %.2lf %s\n", list->expenses[i].amount, list->expenses[i].currency);
        printf("-----------------------------------------\n");
    }
    printf("\n");
}

int main() {
    ExpensesList myExpenses = { 0 };
    int choice = 0;

    do {
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Exit\n");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&myExpenses);
                break;
            case 2:
                displayExpenses(&myExpenses);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}