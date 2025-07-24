//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expense {
    char name[100];
    float amount;
    char category[100];
};

int main() {
    int num_expenses;
    printf("How many expenses would you like to log? ");
    scanf("%d", &num_expenses);

    struct expense* expenses = (struct expense*)malloc(num_expenses * sizeof(struct expense));

    for(int i = 0; i < num_expenses; i++) {
        printf("\nExpense %d\n", i+1);
        printf("Name: ");
        getchar();
        fgets(expenses[i].name, 100, stdin);
        printf("Amount: ");
        scanf("%f", &expenses[i].amount);
        printf("Category: ");
        getchar();
        fgets(expenses[i].category, 100, stdin);
    }

    printf("\nTotal Expenses:\n\n");

    for(int i = 0; i < num_expenses; i++) {
        printf("%s | $%.2f | %s", expenses[i].name, expenses[i].amount, expenses[i].category);
    }

    free(expenses);

    return 0;
}