//FormAI DATASET v1.0 Category: Expense Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char category[50];
    float amount;
};

int main() {
    int numExpenses, i;
    float totalExpenses = 0.0;
    struct Expense* expenses;
    
    printf("Welcome to Expense Tracker! How many expenses did you have this month? ");
    scanf("%d", &numExpenses);
    
    expenses = (struct Expense*)malloc(numExpenses * sizeof(struct Expense));
    
    for (i = 0; i < numExpenses; i++) {
        printf("\nEnter information for expense #%d:", i+1);
        
        printf("\nCategory: ");
        scanf("%s", &expenses[i].category);
        
        printf("Amount: $");
        scanf("%f", &expenses[i].amount);
        
        totalExpenses += expenses[i].amount;
    }
    
    printf("\n\n------ EXPENSE REPORT ------\n");
    printf("CATEGORY \t AMOUNT\n");
    
    for (i = 0; i < numExpenses; i++) {
        printf("%s \t\t $%.2f\n", expenses[i].category, expenses[i].amount);
    }
    
    printf("----------------------------------\n");
    printf("TOTAL EXPENSES: \t $%.2f\n\n", totalExpenses);
    
    free(expenses);

    return 0;
}