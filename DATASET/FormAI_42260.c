//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char date[11];
    char description[50];
    float amount;
};

int main() {
    int numExpenses;
    float totalExpenses = 0;

    printf("Enter the number of expenses to track: ");
    scanf("%d", &numExpenses);

    struct Expense expenses[numExpenses];

    for(int i = 0; i < numExpenses; i++) {
        printf("Expense #%d:\n", i + 1);
        printf("Enter the date in yyyy-mm-dd format: ");
        scanf("%s", expenses[i].date);
        printf("Enter a brief description of the expense: ");
        scanf("%s", expenses[i].description);
        printf("Enter the expense amount: ");
        scanf("%f", &expenses[i].amount);
        totalExpenses += expenses[i].amount;
    }

    printf("\nExpense Report:\n");
    printf("=================\n");
    printf("%-12s %-20s %s\n", "Date", "Description", "Amount");
    printf("----------------------------------------------------\n");
    for(int i = 0; i < numExpenses; i++) {
        printf("%-12s %-20s $%-10.2f\n", expenses[i].date, expenses[i].description, expenses[i].amount);
    }
    printf("----------------------------------------------------\n");
    printf("%-12s %-20s $%-10.2f\n", "Total", "", totalExpenses);

    return 0;
}