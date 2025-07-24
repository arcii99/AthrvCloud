//FormAI DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 20

struct Expense {
    char category[MAX_LENGTH];
    float amount;
    struct Expense* next;
};

typedef struct Expense Expense;

Expense* createExpense(char category[MAX_LENGTH], float amount) {
    Expense* expense = (Expense*) malloc(sizeof(Expense));
    strcpy(expense->category, category);
    expense->amount = amount;
    expense->next = NULL;
    return expense;
}

void addExpense(Expense** start, char category[MAX_LENGTH], float amount) {
    Expense* expense = createExpense(category, amount);
    Expense* temp = *start;
    if (*start == NULL) {
        *start = expense;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = expense;
}

void displayExpenses(Expense** start) {
    Expense* temp = *start;
    float total = 0;
    printf("CATEGORY\tAMOUNT\n");
    while (temp != NULL) {
        printf("%s\t\t%.2f\n", temp->category, temp->amount);
        total += temp->amount;
        temp = temp->next;
    }
    printf("TOTAL:\t\t%.2f\n", total);
}

int main() {
    Expense* start = NULL;
    int option = 0;
    do {
        printf("\n--- EXPENSE TRACKER MENU ---\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                char category[MAX_LENGTH];
                float amount;
                printf("Enter category: ");
                scanf("%s", category);
                printf("Enter amount: ");
                scanf("%f", &amount);
                addExpense(&start, category, amount);
                printf("\nExpense added successfully!\n");
                break;
            case 2:
                displayExpenses(&start);
                break;
            case 3:
                printf("\nExiting Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("\nInvalid option! Please choose again.\n");
                break;
        }
    } while (option != 3);
    return 0;
}