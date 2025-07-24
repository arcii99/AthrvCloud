//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char* name;
    double amount;
};

int numExpenses = 0;
struct Expense expenses[MAX_EXPENSES];

double totalExpenses() {
    double total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void addExpense(char* name, double amount) {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Max expenses exceeded. Please remove an expense before adding another.\n");
        return;
    }

    struct Expense newExpense;
    newExpense.name = (char*)malloc(strlen(name) + 1);
    strcpy(newExpense.name, name);
    newExpense.amount = amount;
    expenses[numExpenses] = newExpense;
    numExpenses++;
}

void removeExpense(int index) {
    if (index < 0 || index >= numExpenses) {
        printf("Invalid index.\n");
        return;
    }

    free(expenses[index].name);
    for (int i = index; i < numExpenses - 1; i++) {
        expenses[i] = expenses[i+1];
    }
    numExpenses--;
}

void printExpenses() {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%d. %s - $%.2f\n", i+1, expenses[i].name, expenses[i].amount);
    }
}

void printTotal() {
    printf("Total Expenses: $%.2f\n", totalExpenses());
}

int main() {
    char input[100];

    while (1) {
        printf("Enter command: ");
        fgets(input, 100, stdin);

        if (strcmp(input, "quit\n") == 0) {
            break;
        } else if (strcmp(input, "print\n") == 0) {
            printExpenses();
        } else if (strcmp(input, "add\n") == 0) {
            printf("Enter name of expense: ");
            fgets(input, 100, stdin);
            input[strlen(input)-1] = '\0';

            double amount;
            printf("Enter amount: ");
            scanf("%lf", &amount);
            getchar();

            addExpense(input, amount);
        } else if (strcmp(input, "remove\n") == 0) {
            printf("Enter index of expense to remove: ");
            int index;
            scanf("%d", &index);
            getchar();

            removeExpense(index-1);
        } else if (strcmp(input, "total\n") == 0) {
            printTotal();
        } else {
            printf("Invalid command.\n");
        }
    }

    for (int i = 0; i < numExpenses; i++) {
        free(expenses[i].name);
    }

    return 0;
}