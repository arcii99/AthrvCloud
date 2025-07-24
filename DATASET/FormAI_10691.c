//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>

int main() {
    float total_income, total_expense = 0, savings_goal;
    int num_of_expenses;
    
    printf("Welcome to Personal Finance Planner!\n");
    printf("Enter your total monthly income: ");
    scanf("%f", &total_income);
    
    printf("\nHow much do you want to save this month? ");
    scanf("%f", &savings_goal);
    
    while (total_expense < total_income-savings_goal) {
        printf("\nEnter number of expenses: ");
        scanf("%d", &num_of_expenses);
        
        float expenses[num_of_expenses];
        
        for (int i=0; i<num_of_expenses; i++) {
            printf("Enter expense #%d: ", i+1);
            scanf("%f", &expenses[i]);
            total_expense += expenses[i];
        }
        
        printf("\nTotal expenses: $%.2f", total_expense);
    }
    
    printf("\n\nYou have reached your savings goal! Congratulations!\n");
    printf("Your remaining budget for the month is $%.2f\n", total_income-total_expense);
    
    return 0;
}