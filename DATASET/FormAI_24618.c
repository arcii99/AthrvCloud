//FormAI DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Expense {
    char category[20];
    float amount;
    char date[20];
};

int main() {
    int numExpenses;
    printf("Welcome to your Expense Tracker!\n");
    printf("How many expenses would you like to enter? ");
    scanf("%d", &numExpenses);

    struct Expense expenses[numExpenses];

    for (int i = 0; i < numExpenses; i++) {
        printf("Enter expense category: ");
        scanf("%s", expenses[i].category);
        printf("Enter expense amount: ");
        scanf("%f", &expenses[i].amount);

        time_t now = time(NULL);
        strftime(expenses[i].date, 20, "%Y-%m-%d", localtime(&now));

        printf("Expense added successfully!\n");
    }

    printf("\nHere are your expenses:\n");
    printf("Category | Amount | Date\n");
    printf("------------------------\n");

    for (int i = 0; i < numExpenses; i++) {
        printf("%-9s| $%.2f | %s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }

    return 0;
}