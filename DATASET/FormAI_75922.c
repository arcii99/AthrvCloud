//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>

// Define a struct to store expenses
struct Expense {
    char category[20];
    float amount;
};

// Function to print an expense
void printExpense(struct Expense ex) {
    printf("%s: $%.2f\n", ex.category, ex.amount);
}

int main() {
    int numExpenses;
    float totalSpent = 0;

    // Ask the user how many expenses they have
    printf("How many expenses do you have? ");
    scanf("%d", &numExpenses);

    // Create an array of expenses based on user input
    struct Expense expenses[numExpenses];
    for (int i = 0; i < numExpenses; i++) {
        printf("Enter expense category #%d (max 20 characters): ", i+1);
        scanf("%s", &(expenses[i].category));

        printf("Enter amount spent: $");
        scanf("%f", &(expenses[i].amount));

        totalSpent += expenses[i].amount; // Add this expense to total amount spent
    }

    // Print out the list of expenses and total amount spent
    printf("\nEXPENSES:\n");
    for (int i = 0; i < numExpenses; i++) {
        printExpense(expenses[i]);
    }
    printf("\nTOTAL SPENT: $%.2f\n", totalSpent);

    return 0;
}