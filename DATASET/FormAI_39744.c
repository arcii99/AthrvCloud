//FormAI DATASET v1.0 Category: Expense Tracker ; Style: brave
#include<stdio.h>
#include<stdlib.h>

struct expense { // Structure to hold the expense details
    char category[20];
    float amount;
};

int main() {
    int num_expenses, i;
    float total_expense = 0;
    printf("Welcome to the Expense Tracker Program!\n");
    printf("How many expenses would you like to record?\n");
    scanf("%d", &num_expenses);
    struct expense expenses[num_expenses]; // Array to hold expense details
    
    // Loop to get and store expense details
    for(i=0; i<num_expenses; i++) {
        printf("\nExpense #%d\n", i+1);
        printf("Enter expense category: ");
        scanf("%s", expenses[i].category);
        printf("Enter expense amount: ");
        scanf("%f", &expenses[i].amount);
        total_expense += expenses[i].amount;
    }
    
    printf("\n\nExpense Report\n");
    printf("------------------------------\n");
    printf("Category\tAmount\n");
    printf("------------------------------\n");
    
    // Loop to print expense details
    for(i=0; i<num_expenses; i++) {
        printf("%s\t\t%.2f\n", expenses[i].category, expenses[i].amount);
    }
    
    printf("------------------------------\n");
    printf("Total Expense:\t%.2f\n", total_expense);
    printf("------------------------------\n");
    
    return 0; // Program executed successfully
}