//FormAI DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char name[20];
    float amount;
};

int main() {

    int num_expenses = 0;
    struct expense expenses[50];

    while (1) {
        printf("Enter the name of the expense (type 'end' when done): ");
        scanf("%s", &expenses[num_expenses].name);

        if (strcmp(expenses[num_expenses].name, "end") == 0) {
            break;
        }

        printf("Enter the amount of the expense: ");
        scanf("%f", &expenses[num_expenses].amount);
        num_expenses++;
    }

    float total = 0;
    printf("\nExpense Report\n");
    printf("---------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
        total += expenses[i].amount;
    }

    printf("\nTotal: $%.2f\n", total);

    return 0;
}