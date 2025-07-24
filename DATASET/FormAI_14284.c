//FormAI DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char description[100];
    float amount;
};

int main() {
    int numExpenses;
    float totalExpenses = 0.0;
    
    printf("How many expenses do you have? ");
    scanf("%d", &numExpenses);
    
    // allocate memory for expenses based on user input
    struct Expense* expenses = malloc(numExpenses * sizeof(struct Expense));
    
    // loop through each expense and ask user for description and amount
    for (int i = 0; i < numExpenses; i++) {
        printf("Enter expense description for expense %d: ", i+1);
        scanf("%s", expenses[i].description);
        
        printf("Enter expense amount for expense %d: ", i+1);
        scanf("%f", &expenses[i].amount);
        
        totalExpenses += expenses[i].amount;
    }
    
    // print out each expense and the total amount spent
    printf("\nExpense Report:\n");
    printf("-----------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].description, expenses[i].amount);
    }
    printf("-----------------\n");
    printf("Total Expenses: $%.2f", totalExpenses);
    
    // free allocated memory
    free(expenses);
    
    return 0;
}