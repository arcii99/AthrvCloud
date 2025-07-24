//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    double amount;
    char description[50];
};

int main() {
    int num_expenses;
    printf("Enter the number of expenses: ");
    scanf("%d", &num_expenses);
    
    struct expense expenses[num_expenses];
    double total_expenses = 0.0;
    
    for(int i = 0; i < num_expenses; i++) {
        double amount;
        char description[50];
        
        printf("Enter description for expense %d: ", i+1);
        scanf("%s", description);
        strcpy(expenses[i].description, description);
        
        printf("Enter amount for expense %d: ", i+1);
        scanf("%lf", &amount);
        expenses[i].amount = amount;
        
        total_expenses += amount;
    }
    
    printf("\nExpenses:\n");
    for(int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2lf\n", expenses[i].description, expenses[i].amount);
    }
    printf("Total expenses: $%.2lf\n", total_expenses);
    
    return 0;
}