//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char type[20];
    float amount;
    int day;
    int month;
    int year;
};

int main() {
    int numExpenses;
    printf("How many expenses would you like to enter?\n");
    scanf("%d", &numExpenses);

    struct Expense expenses[numExpenses];

    for (int i = 0; i < numExpenses; i++) {
        printf("\nEnter expense type (max 20 characters): ");
        scanf("%s", expenses[i].type);
        printf("Enter amount: ");
        scanf("%f", &expenses[i].amount);
        printf("Enter date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &expenses[i].day, &expenses[i].month, &expenses[i].year);
    }

    float total = 0;
    printf("\n-----------------------------------\n");
    printf("  Expense Tracker\n");
    printf("-----------------------------------\n");
    printf("Type\tAmount\tDate\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t%.2f\t%d/%d/%d\n", expenses[i].type, expenses[i].amount, expenses[i].day, expenses[i].month, expenses[i].year);
        total += expenses[i].amount;
    }
    printf("-----------------------------------\n");
    printf("Total\t%.2f\n", total);

    return 0;
}