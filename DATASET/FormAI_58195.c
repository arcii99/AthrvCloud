//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <string.h>

struct Expense {
    char name[20];
    float amount;
};

void printExpense(struct Expense exp) {
    printf("%s\t%.2f\n", exp.name, exp.amount);
}

int main() {
    struct Expense expenses[10];
    char input[20];
    float total = 0;

    printf("Enter expenses (max 10, empty line to end):\n");

    int count = 0;
    while (count < 10) {
        fgets(input, 20, stdin);
        if (strcmp(input, "\n") == 0) {
            break;
        }
        char name[20];
        float amount;
        sscanf(input, "%s %f", name, &amount);
        struct Expense newExpense;
        strcpy(newExpense.name, name);
        newExpense.amount = amount;
        expenses[count] = newExpense;
        count++;
    }

    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printExpense(expenses[i]);
        total += expenses[i].amount;
    }

    printf("Total: %.2f\n", total);

    return 0;
}