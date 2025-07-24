//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
// Ephemeral style Expense Tracker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct expense {
    char name[50];
    float amount;
    char category[20];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    Expense e;
    printf("Enter Expense Name: ");
    scanf("%s", e.name);
    printf("Enter Expense Amount: ");
    scanf("%f", &e.amount);
    printf("Enter Expense Category: ");
    scanf("%s", e.category);
    expenses[num_expenses] = e;
    num_expenses += 1;
    printf("Expense Added Successfully!\n");
}

void view_expenses() {
    float total = 0;
    printf("\nName\tAmount\tCategory\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
        total += expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void search_expenses() {
    char query[50];
    printf("Enter Search Query: ");
    scanf("%s", query);
    printf("\nName\tAmount\tCategory\n");
    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strstr(expenses[i].name, query) != NULL) {
            printf("%s\t%.2f\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
            found = 1;
        }
    }
    if (!found) {
        printf("No Expenses Found!\n");
    }
}

void delete_expense() {
    char name[50];
    printf("Enter Expense Name: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            for (int j = i; j < num_expenses - 1; j++) {
                expenses[j] = expenses[j + 1];
            }
            num_expenses -= 1;
            found = 1;
            printf("Expense Deleted Successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Expense Not Found!\n");
    }
}

int main() {
    int choice;
    do {
        printf("Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Search Expenses\n");
        printf("4. Delete Expense\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                search_expenses();
                break;
            case 4:
                delete_expense();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid Choice. Try Again!\n");
        }
    } while (1);

    return 0;
}