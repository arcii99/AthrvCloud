//FormAI DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char name[50];
    int amount;
};

int main() {
    int count = 0;
    int total = 0;
    struct expense *expenses = NULL;

    printf("Welcome to My Expense Tracker\n\n");

    while (1) {
        printf("Enter expense name (or 'quit' to exit): ");
        char name[50];
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        count++;
        expenses = realloc(expenses, count * sizeof(struct expense));
        struct expense *cur = &expenses[count - 1];

        strcpy(cur->name, name);
        printf("Enter expense amount: ");
        scanf("%d", &cur->amount);

        total += cur->amount;
        printf("Total expenses so far: $%d\n\n", total);
    }

    printf("Total expenses: $%d\n", total);
    printf("Expense details:\n\n");

    for (int i = 0; i < count; i++) {
        struct expense *cur = &expenses[i];
        printf("%s: $%d\n", cur->name, cur->amount);
    }

    free(expenses);
    return 0;
}