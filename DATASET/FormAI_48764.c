//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char item[100];
    float amount;
};

struct income {
    char source[100];
    float amount;
};

struct savings {
    float amount;
};

struct account {
    float balance;
    struct expense expenses[100];
    struct income incomes[100];
    struct savings savings;
};

struct account acc;

void addExpense(char item[], float amount) {
    int i = 0;
    while (acc.expenses[i].amount > 0) {
        i++;
    }
    strcpy(acc.expenses[i].item, item);
    acc.expenses[i].amount = amount;
    acc.balance -= amount;
    printf("%s added to expenses. Remaining balance: %f\n", item, acc.balance);
}

void addIncome(char source[], float amount) {
    int i = 0;
    while (acc.incomes[i].amount > 0) {
        i++;
    }
    strcpy(acc.incomes[i].source, source);
    acc.incomes[i].amount = amount;
    acc.balance += amount;
    printf("%s added as income. Remaining balance: %f\n", source, acc.balance);
}

void addSavings(float amount) {
    acc.savings.amount += amount;
    acc.balance -= amount;
    printf("Savings added. Remaining balance: %f\n", acc.balance);
}

int main() {

    // Initialize account balance at $5000
    acc.balance = 5000.0;

    // Add expenses
    addExpense("Groceries", 200.0);
    addExpense("Gas", 50.0);

    // Add income
    addIncome("Wages", 1000.0);

    // Add savings
    addSavings(500.0);

    return 0;
}