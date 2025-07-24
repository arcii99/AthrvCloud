//FormAI DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>

// struct to hold the details of each expense
typedef struct {
    char name[50];
    float amount;
    char category[20];
} Expense;

int main() {
    int numExpenses;
    printf("Welcome to your expense tracker!\n");
    printf("How many expenses would you like to add? ");
    scanf("%d", &numExpenses);
    
    // dynamically allocate memory for an array of expenses
    Expense *expenses = (Expense*) malloc(sizeof(Expense) * numExpenses);
    
    // loop through and get details for each expense
    for (int i=0; i<numExpenses; i++) {
        printf("\nExpense #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", (expenses + i)->name);
        printf("Amount: ");
        scanf("%f", &(expenses + i)->amount);
        printf("Category: ");
        scanf("%s", (expenses + i)->category);
    }
    
    // print out all expenses
    printf("\nHere are all of your expenses:\n");
    for (int i=0; i<numExpenses; i++) {
        printf("%d. Name: %s \n   Amount: $%.2f \n   Category: %s\n", i+1, (expenses + i)->name, (expenses + i)->amount, (expenses + i)->category);
    }
    
    // free allocated memory
    free(expenses);
    
    printf("\nThank you for using your expense tracker!\n");
    return 0;
}