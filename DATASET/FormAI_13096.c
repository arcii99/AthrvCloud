//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char description[100];
    float amount;
};

int main() {
    int num_expenses;
    printf("How many expenses do you want to track? ");
    scanf("%d", &num_expenses);

    struct expense* exp_list;
    exp_list = (struct expense*) malloc(num_expenses * sizeof(struct expense));

    if (exp_list == NULL) {
        printf("Error: Insufficient Memory\n");
        exit(1);
    }

    printf("\nEnter Details of %d Expenses\n\n", num_expenses);
    for (int i = 0; i < num_expenses; i++) {
        printf("Expense #%d\n", i+1);
        printf("Description: ");
        scanf("%s", exp_list[i].description);
        printf("Amount: ");
        scanf("%f", &exp_list[i].amount);
    }

    float total_expense = 0;
    printf("\n----------------------------------\n");
    printf("Expense Summary\n");
    printf("----------------------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s: %.2f\n", i+1, exp_list[i].description, exp_list[i].amount);
        total_expense += exp_list[i].amount;
    }

    printf("----------------------------------\n");
    printf("Total Expenses: %.2f\n", total_expense);

    free(exp_list);
    return 0;
}