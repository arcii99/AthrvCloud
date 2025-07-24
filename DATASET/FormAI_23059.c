//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    double budget;
} Expense;

void print_expense(Expense *e) {
    printf("%s: $%.2f\n", e->name, e->budget);
}

int main()
{
    int n, i;
    double total_budget = 0;

    printf("Welcome to the Personal Finance Planner!\n\n");

    printf("Enter the number of expenses: ");
    scanf("%d", &n);

    Expense expenses[n];

    for (i = 0; i < n; i++) {
        printf("Enter expense %d name: ", i+1);
        scanf("%s", expenses[i].name);

        printf("Enter expense %d budget: $", i+1);
        scanf("%lf", &expenses[i].budget);

        total_budget += expenses[i].budget;
    }

    printf("\nYour expenses:\n");

    for (i = 0; i < n; i++) {
        print_expense(&expenses[i]);
    }

    printf("\nTotal budget: $%.2f\n", total_budget);

    printf("\nRecommended monthly budget: $%.2f\n", total_budget / 12);

    return 0;
}