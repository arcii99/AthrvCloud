//FormAI DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char name[50];
    int amount;
};

int main() {
    int n, totalExpenses = 0;
    printf("Enter the total number of expenses: ");
    scanf("%d", &n);
    
    struct Expense expenses[n];
    
    // Get the expenses details
    for (int i = 0; i < n; i++) {
        printf("\nEnter expense name: ");
        scanf("%s", expenses[i].name);
        
        printf("Enter expense amount: ");
        scanf("%d", &expenses[i].amount);
        
        totalExpenses += expenses[i].amount;
    }
    
    // Print the expenses details
    printf("\n\nExpense Details\n");
    printf("----------------------------------\n");
    printf("Name\t\tAmount\n");
    printf("----------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\n", expenses[i].name, expenses[i].amount);
    }
    printf("----------------------------------\n");
    printf("Total\t\t%d\n", totalExpenses);
    printf("----------------------------------\n");
    
    return 0;
}