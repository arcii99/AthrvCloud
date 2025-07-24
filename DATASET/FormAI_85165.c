//FormAI DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>

/* Create a struct to store expenses */
struct Expense {
    char item[20];
    float price;
};

int main() {
    /* Initialize variables */
    int numExpenses, i;
    float totalExpense = 0;

    /* Prompt user for number of expenses */
    printf("How many expenses would you like to input? ");
    scanf("%d", &numExpenses);

    /* Create an array of structs to hold expenses */
    struct Expense expenses[numExpenses];

    /* Loop through array to input expenses */
    for (i = 0; i < numExpenses; i++) {
        printf("Enter item %d: ", i+1);
        scanf("%s", &expenses[i].item);

        printf("Enter price: ");
        scanf("%f", &expenses[i].price);

        /* Add price to total expense */
        totalExpense += expenses[i].price;
    }

    /* Print out expenses and total expense */
    printf("Expenses:\n");
    for (i = 0; i < numExpenses; i++) {
        printf("%s - $%.2f\n", expenses[i].item, expenses[i].price);
    }
    printf("Total Expense: $%.2f", totalExpense);

    /* End the program */
    return 0;
}