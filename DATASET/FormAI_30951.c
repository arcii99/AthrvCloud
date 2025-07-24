//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Touring
#include <stdio.h>

int main() {
    float income, expenses, savings;
    
    printf("Welcome to the Personal Finance Planner!\n\n");
    
    // get user input for income
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    
    // get user input for expenses
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);
    
    // calculate savings
    savings = income - expenses;
    
    // display results to user
    printf("\nIncome:\t\t$%.2f\nExpenses:\t$%.2f\nSavings:\t$%.2f\n", income, expenses, savings);
    
    // determine if user is in debt or able to save money
    if (savings < 0) {
        printf("Uh-oh, you're in debt!\n");
    } else if (savings == 0) {
        printf("You're breaking even.\n");
    } else {
        printf("Great job! You're able to save money each month.\n");
    }
    
    return 0;
}