//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char date[20];
    char category[20];
    float amount;
};

int main() {

    int numExpenses;
    printf("How many expenses would you like to enter? ");
    scanf("%d", &numExpenses);

    struct Expense expenses[numExpenses];
    printf("\n");

    for(int i = 0; i < numExpenses; i++) {
        printf("Expense %d: \n", i+1);
        printf("Date (mm/dd/yyyy): ");
        scanf("%s", &expenses[i].date);
        printf("Category: ");
        scanf("%s", &expenses[i].category);
        printf("Amount: $");
        scanf("%f", &expenses[i].amount);
        printf("\n");
    }

    printf("-----------------\n");
    printf("Expense Summary:\n");
    printf("-----------------\n\n");

    float totalExpenses = 0;
    for(int i = 0; i < numExpenses; i++) {
        printf("Expense %d: \n", i+1);
        printf("Date: %s\n", expenses[i].date);
        printf("Category: %s\n", expenses[i].category);
        printf("Amount: $%.2f\n", expenses[i].amount);
        totalExpenses += expenses[i].amount;
        printf("\n");
    }

    printf("-----------------\n");
    printf("Total expenses: $%.2f\n", totalExpenses);

    return 0;
}