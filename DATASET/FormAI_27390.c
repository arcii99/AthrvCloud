//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct Expense {
    float amount;
    char category[50];
    char date[20];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(float amount, char category[], char date[]) {
    if (num_expenses == MAX_EXPENSES) {
        printf("Maximum number of expenses reached.");
        return;
    }
    expenses[num_expenses].amount = amount;
    strcpy(expenses[num_expenses].category, category);
    strcpy(expenses[num_expenses].date, date);
    num_expenses++;
}

void print_expenses() {
    if (num_expenses == 0) {
        printf("No expenses recorded yet.");
        return;
    }
    printf("Amount\tCategory\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%.2f\t%s\t%s\n", expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

void print_total_by_category(char category[]) {
    float total = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            total += expenses[i].amount;
        }
    }
    printf("Total spent on %s: $%.2f\n", category, total);
}

void print_menu() {
    printf("\nExpense Tracker Menu\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total by Category\n");
    printf("4. Quit\n");
}

int main() {
    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                float amount;
                char category[50], date[20];
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                printf("Enter expense category: ");
                scanf("%s", category);
                printf("Enter date (MM/DD/YYYY): ");
                scanf("%s", date);
                add_expense(amount, category, date);
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                char filter_category[50];
                printf("Enter category to filter by: ");
                scanf("%s", filter_category);
                print_total_by_category(filter_category);
                break;
            case 4:
                printf("Program terminated.");
                break;
            default:
                printf("Invalid choice. Please try again.");
                break;
        }
    } while (choice != 4);
    return 0;
}