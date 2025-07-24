//FormAI DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

struct expense {
    int expense_id;
    char category[50];
    float amount;
};

int main() {
    int num_expenses;
    printf("Enter the number of expenses: ");
    scanf("%d", &num_expenses);

    struct expense *expenses = (struct expense*) malloc(num_expenses * sizeof(struct expense));

    // Get expense details from user
    for (int i = 0; i < num_expenses; i++) {
        printf("\nEnter expense %d details:\n", i+1);
        printf("Expense ID: ");
        scanf("%d", &expenses[i].expense_id);
        printf("Category: ");
        scanf("%s", expenses[i].category);
        printf("Amount: ");
        scanf("%f", &expenses[i].amount);
    }

    // Display expense details
    printf("\n--- Expense Tracker ---\n");
    printf("Expense ID | Category | Amount\n");
    printf("--------------------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-11d| %-9s| $%.2f\n", expenses[i].expense_id, expenses[i].category, expenses[i].amount);
    }

    free(expenses);
    return 0;
}