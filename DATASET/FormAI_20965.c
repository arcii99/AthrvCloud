//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[20];
    float amount;
};

int main() {
    int num_expenses;
    struct Expense *expenses;

    printf("How many expenses do you want to track? ");
    scanf("%d", &num_expenses);

    expenses = (struct Expense *)malloc(num_expenses * sizeof(struct Expense));

    for (int i = 0; i < num_expenses; i++) {
        printf("Enter category for expense %d: ", i+1);
        scanf("%s", expenses[i].category);
        printf("Enter amount for expense %d: ", i+1);
        scanf("%f", &(expenses[i].amount));
    }

    printf("\n---------- EXPENSES ----------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d) %s: $%.2f\n", i+1, expenses[i].category, expenses[i].amount);
    }
    printf("-----------------------------\n");

    float total_expenses = 0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
    }
    printf("\nTotal Expenses: $%.2f\n", total_expenses);

    free(expenses);
    return 0;
}