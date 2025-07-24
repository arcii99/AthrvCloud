//FormAI DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    int expenses[31];
    int totalExpenses = 0;
    int day = 1;
    printf("Welcome to the Expense Tracker App!\n");

    while(day < 31) {
        int expense;
        printf("\nEnter your expense for day %d: ", day);
        scanf("%d", &expense);
        if (expense < 0) {
            printf("Please enter a valid amount!\n");
            continue;
        }
        expenses[day-1] = expense;
        totalExpenses += expense;
        printf("Added expense of %d for day %d\n", expense, day++);
    }

    printf("\n************************************\n");
    printf("*********** EXPENSE REPORT *********\n");
    printf("************************************\n\n");

    for (int i = 0; i < 30; i++) {
        printf("Day %d: %d\n", i+1, expenses[i]);
    }

    printf("\n\nTotal Expenses: %d\n", totalExpenses);

    printf("\n************************************\n");
    printf("*********** THANK YOU! ************\n");
    printf("************************************\n");

    return 0;
}