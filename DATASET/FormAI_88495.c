//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

struct expenses {
    char name[50];
    float amount;
};

int main() {
    int num_expenses, i;
    float total_amount = 0;
    
    printf("Enter the number of expenses: ");
    scanf("%d", &num_expenses);
    
    struct expenses expenses_list[num_expenses];
    
    for (i=0; i<num_expenses; i++) {
        printf("\nEnter expense name: ");
        scanf("%s", expenses_list[i].name);
        
        printf("Enter expense amount: ");
        scanf("%f", &expenses_list[i].amount);
        
        total_amount += expenses_list[i].amount;
    }
    
    printf("\n\n------------EXPENSES REPORT------------\n\n");
    printf("Expense Name\t\tExpense Amount\n");
    printf("-----------\t\t--------------\n");
    
    for (i=0; i<num_expenses; i++) {
        printf("%-20s\t\t$%.2f\n", expenses_list[i].name, expenses_list[i].amount);
    }
    
    printf("\nTotal Expenses: $%.2f\n", total_amount);
    
    return 0;
}