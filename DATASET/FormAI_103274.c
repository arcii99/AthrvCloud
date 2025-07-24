//FormAI DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int expenses[30], total_expenses = 0;
    char option;
    do {
        printf("Enter the expense for the day: ");
        scanf("%d", &expenses[total_expenses]);
        total_expenses++;
        printf("Do you want to add another expense? (Y/N) ");
        scanf("%s", &option);
    } while(option == 'Y' || option == 'y');

    printf("\n\n");

    printf("Date       | Expense\n");
    printf("--------------------\n");
    for(int i = 0; i < total_expenses; i++) {
        printf("%d/%d/%d | $%d\n", (i+1), 10, 2021, expenses[i]);
    }

    printf("--------------------\n");
    printf("Total      | $%d\n", total_expenses);

    return 0;
}