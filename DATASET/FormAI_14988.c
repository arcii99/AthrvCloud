//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50

typedef struct {
    float amount;
    char category[20];
    char date[11];
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (1) {
        printf("Enter expense amount: ");
        float amount;
        scanf("%f", &amount);
        expenses[num_expenses].amount = amount;

        printf("Enter expense category: ");
        char category[20];
        scanf("%s", category);
        strcpy(expenses[num_expenses].category, category);

        printf("Enter expense date (mm/dd/yyyy): ");
        char date[11];
        scanf("%s", date);
        strcpy(expenses[num_expenses].date, date);

        num_expenses++;

        printf("Would you like to add another expense? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    printf("\n\n-----------------Expenses-----------------\n\n");
    printf("Amount       Category          Date\n");
    printf("------       --------          ----\n");

    int i;
    for (i = 0; i < num_expenses; i++) {
        printf("%-12.2f %-16s %s \n", expenses[i].amount, expenses[i].category, expenses[i].date);
    }

    printf("\n\n---------------Expenses Summary----------------\n\n");
    printf("Category         Total\n");
    printf("--------         -----\n");

    float total_spent = 0;

    for (i = 0; i < num_expenses; i++) {
        total_spent += expenses[i].amount;
    }

    printf("Total Spent      $%.2f\n", total_spent);

    char categories[MAX_EXPENSES][20];
    int counts[MAX_EXPENSES];
    int distinct_category_count = 0;

    for (i = 0; i < num_expenses; i++) {
        int j;
        for (j = 0; j < distinct_category_count; j++) {
            if (strcmp(expenses[i].category, categories[j]) == 0) {
                counts[j]++;
                break;
            }
        }
        if (j == distinct_category_count) {
            strcpy(categories[distinct_category_count], expenses[i].category);
            counts[distinct_category_count] = 1;
            distinct_category_count++;
        }
    }

    for (i = 0; i < distinct_category_count; i++) {
        printf("%-16s %d\n", categories[i], counts[i]);
    }

    return 0;
}