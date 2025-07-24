//FormAI DATASET v1.0 Category: Expense Tracker ; Style: optimized
#include<stdio.h>

#define MAX_EXPENSES 1000 // Maximum number of expenses that the program can handle.

int main()
{
    char expenses[MAX_EXPENSES][100]; // Two-dimensional array to store each expense and its description.
    float cost[MAX_EXPENSES]; // Array to store the cost of each expense.
    int numExpenses = 0; // Variable to keep track of the current number of expenses.
    float totalSpent = 0; // Variable to keep track of the total amount spent.

    while(1) { // Loop to keep accepting new expenses until the user chooses to exit.

        // Prompt the user to enter an expense and its cost.
        printf("\nEnter an expense (or type 'exit' to quit): ");
        fgets(expenses[numExpenses], 100, stdin);
        expenses[numExpenses][strlen(expenses[numExpenses])-1] = '\0'; // Remove the newline character from the input.

        if(strcmp(expenses[numExpenses], "exit") == 0) { // If the user entered 'exit', break the loop.
            break;
        }

        printf("Enter the cost: ");
        scanf("%f", &cost[numExpenses]);

        getchar(); // Consume the newline character from the previous input.

        // Add the cost of the new expense to the total spent and update the number of expenses.
        totalSpent += cost[numExpenses];
        numExpenses++;

        if(numExpenses == MAX_EXPENSES) { // If the maximum number of expenses has been reached, break the loop.
            printf("Maximum number of expenses reached.\n");
            break;
        }
    }

    // Print a table of all expenses and their costs.
    printf("\n%-20s%-10s\n---------------  ----------\n", "Expense", "Cost");
    for(int i=0; i<numExpenses; i++) {
        printf("%-20s$%-10.2f\n", expenses[i], cost[i]);
    }

    // Print the total amount spent and the average cost per expense.
    printf("\nTotal spent: $%.2f\n", totalSpent);
    printf("Average cost per expense: $%.2f\n", totalSpent/numExpenses);

    return 0;
}